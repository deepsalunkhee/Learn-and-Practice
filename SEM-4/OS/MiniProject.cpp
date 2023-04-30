#include <QApplication>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QSpinBox>
#include <QTableView>
#include <QStandardItemModel>
#include <iostream>
#include <vector>

using namespace std;

int NoOfProcess, NoOfResources;
vector<vector<int>> Allocation;
vector<vector<int>> MaxNeed;
vector<vector<int>> Need;
vector<int> MaxInstances;

vector<int> CurrentlyAvailable;
vector<int> AvailvleAfterGiving;

void SimpleFill(vector<vector<int>> &matrix, int rows, int columns)
{
    matrix.clear();
    for (int i = 0; i < rows; i++)
    {
        vector<int> temp(0);

        for (int j = 0; j < columns; j++)
        {
            int temp1;
            temp1 = matrix[i][j];
            temp.push_back(temp1);
        }
        matrix.push_back(temp);
    }
}

void CalNeed(vector<vector<int>> &matrix, int rows, int columns)
{
    matrix.clear();
    for (int i = 0; i < rows; i++)
    {
        vector<int> temp(0);

        for (int j = 0; j < columns; j++)
        {
            int temp1;
            temp1 = MaxNeed[i][j] - Allocation[i][j];
            temp.push_back(temp1);
        }
        matrix.push_back(temp);
    }
}

void maxFill(vector<int> &matrix, int columns)
{
    matrix.clear();
    for (int i = 0; i < columns; i++)
    {
        int temp;
        temp = matrix[i];
        matrix.push_back(temp);
    }
}

void print2D(vector<vector<int>> &matrix, int rows, int columns, QStandardItemModel *model)
{
    model->setRowCount(rows);
    model->setColumnCount(columns);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            QStandardItem *item = new QStandardItem(QString::number(matrix[i][j]));
            model->setItem(i, j, item);
        }
    }
}

void print1D(vector<int> &matrix, int columns, QStandardItemModel *model)
{
    model->setRowCount(1);
    model->setColumnCount(columns);

    for (int j = 0; j < columns; j++)
    {
        QStandardItem *item = new QStandardItem(QString::number(matrix[j]));
        model->setItem(0, j, item);
    }
}

void CalCA()
{
    CurrentlyAvailable.clear();
    for (int j = 0; j < NoOfResources; j++)
    {
        int temp = 0;
        for (int i = 0; i < NoOfProcess; i++)
        {
            temp += Allocation[i][j];
        }
        CurrentlyAvailable.push_back(MaxInstances[j] - temp);
    }
}

void Banker(QStandardItemModel *model)
{
    // Step 1: Calculate the currently available resources
    CalCA();

    // Step 2: Initialize the visited and answer vectors
    vector<bool> visited(NoOfProcess, false);
    vector<int> ans;

    // Step 3: Repeat until all processes have been visited
    while (ans.size() != NoOfProcess)
    {
        // Step 4: Find a process that can be completed with the currently available resources
        int currProc = -1;
        for (int i = 0; i < NoOfProcess; i++)
        {
            if (!visited[i])
            {
                bool canBeCompleted = true;
                for (int j = 0; j < NoOfResources; j++)
                {
                    if (Need[i][j] > CurrentlyAvailable[j])
                    {
                        canBeCompleted = false;
                        break;
                    }
                }
                if (canBeCompleted)
                {
                    currProc = i;
                    break;
                }
            }
        }
        // Step 5: If no such process exists, then the system is in an unsafe state
        if (currProc == -1)
        {
            cout << "The system is in an unsafe state.\n";
            return;
        }

        // Step 6: Add the resources released by this process to the currently available resources
        for (int j = 0; j < NoOfResources; j++)
        {
            CurrentlyAvailable[j] += Allocation[currProc][j];
        }

        // Step 7: Mark the current process as visited and add it to the answer
        visited[currProc] = true;
        ans.push_back(currProc);
    }

    // Step 8: Print the safe sequence
    cout << "The safe sequence is: ";
    for (int i = 0; i < NoOfProcess; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    // Step 9: Update the model to show the available resources after the last process has finished
    print1D(CurrentlyAvailable, NoOfResources, model);
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    // Create the main window and layout
    QWidget *window = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout;

    // Create the form layout for the input fields
    QFormLayout *formLayout = new QFormLayout;

    // Add the input fields for the number of processes and resources
    QLineEdit *processLineEdit = new QLineEdit;
    formLayout->addRow(new QLabel("Number of processes:"), processLineEdit);

    QLineEdit *resourceLineEdit = new QLineEdit;
    formLayout->addRow(new QLabel("Number of resources:"), resourceLineEdit);

    // Add the input fields for the allocation matrix
    QTableView *allocationTableView = new QTableView;
    QStandardItemModel *allocationModel = new QStandardItemModel;
    allocationTableView->setModel(allocationModel);
    formLayout->addRow(new QLabel("Allocation matrix:"), allocationTableView);

    // Add the input fields for the maximum need matrix
    QTableView *maxNeedTableView = new QTableView;
    QStandardItemModel *maxNeedModel = new QStandardItemModel;
    maxNeedTableView->setModel(maxNeedModel);
    formLayout->addRow(new QLabel("Maximum need matrix:"), maxNeedTableView);

    // Add the input field for the maximum instances vector
    QLineEdit *maxInstancesLineEdit = new QLineEdit;
    formLayout->addRow(new QLabel("Maximum instances vector:"), maxInstancesLineEdit);

    // Add the button to run the banker's algorithm
    QPushButton *runButton = new QPushButton("Run");
    formLayout->addWidget(runButton);

    // Add the output field for the currently available resources vector
    QTableView *availableTableView = new QTableView;
    QStandardItemModel *availableModel = new QStandardItemModel;
    availableTableView->setModel(availableModel);
    layout->addWidget(availableTableView);

    // Add the output field for the safe sequence vector
    QTableView *safeSequenceTableView = new QTableView;
    QStandardItemModel *safeSequenceModel = new QStandardItemModel;
    safeSequenceTableView->setModel(safeSequenceModel);
    layout->addWidget(safeSequenceTableView);

    // Add the form layout to the main layout
    layout->addLayout(formLayout);

    // Set the main window layout
    window->setLayout(layout);

    // Connect the run button to the Banker's algorithm function
    QObject::connect(
        runButton, &QPushButton::clicked, = {
            // Step 0: Clear previous data
            Allocation.clear();
            MaxNeed.clear();
            MaxInstances.clear();
            // Step 1: Get the input data
            NoOfProcess = processLineEdit->text().toInt();
            NoOfResources = resourceLineEdit->text().toInt();

            // Get the allocation matrix input data
            for (int i = 0; i < NoOfProcess; i++)
            {
                vector<int> row;
                for (int j = 0; j < NoOfResources; j++)
                {
                    QModelIndex index = allocationModel->index(i, j);
                    int value = allocationModel->data(index).toInt();
                    row.push_back(value);
                }
                Allocation.push_back(row);
            }

            // Get the maximum need matrix input data
            for (int i = 0; i < NoOfProcess; i++)
            {
                vector<int> row;
                for (int j = 0; j < NoOfResources; j++)
                {
                    QModelIndex index = maxNeedModel->index(i, j);
                    int value = maxNeedModel->data(index).toInt();
                    row.push_back(value);
                }
                MaxNeed.push_back(row);
            }

            // Get the maximum instances vector input data
            vector<int> row;
            QStringList maxInstancesList = maxInstancesLineEdit->text().split(",");
            for (int i = 0; i < NoOfResources; i++)
            {
                row.push_back(maxInstancesList[i].toInt());
            }
            MaxInstances = row;

            // Step 2: Calculate the need matrix
            CalNeed(Need, NoOfProcess, NoOfResources);

            // Step 3: Run the Banker's algorithm
            Banker(safeSequenceModel);

            // Step 4: Update the output fields
            print1D(CurrentlyAvailable, NoOfResources, availableModel);
            print1D(ans, NoOfProcess, safeSequenceModel);
        });

    // Show the main window
    window->show();

    // Run the event loop
    return app.exec();
}

//g++ -I/C/:Qt/6.5.0/mingw_64/include-L/C/:Qt/6.5.0/mingw_64/lib -lQT MiniProject.cpp -o MiniProject

