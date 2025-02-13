#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>

using namespace std;

void printThetas(vector<float>& thetas) {
    for (float theta : thetas) {
        cout << theta << " ";
    }
    cout << endl;
}

float computeMSE(vector<float>& y_cap, vector<float>& target) {
    float mse = 0.0;
    int n = target.size();
    for (int i = 0; i < n; i++) {
        mse += pow(target[i] - y_cap[i], 2);
    }
    return mse / n;
}

void gradientDescent(vector<float>& thetas, vector<vector<float>>& data, vector<float>& target, int tc, int tl, float lr, int epochs) {
    for (int epoch = 1; epoch <= epochs; epoch++) {
        vector<float> y_cap(tl);
        
        for (int i = 0; i < tl; i++) {
            float c_y_cap = thetas[0];
            for (int j = 0; j < tc - 1; j++) {
                c_y_cap += data[i][j] * thetas[j + 1];
            }
            y_cap[i] = c_y_cap;
        }
        
        for (int i = 0; i < tc; i++) {
            float sum = 0.0;
            for (int j = 0; j < tl; j++) {
                if (i == 0) {
                    sum += target[j] - y_cap[j];
                } else {
                    sum += (target[j] - y_cap[j]) * data[j][i - 1];
                }
            }
            thetas[i] -= (lr * (-sum / tl));
        }
        
        float mse = computeMSE(y_cap, target);
        cout << "Epoch " << epoch << " MSE: " << mse << endl;
        cout << "Weights: ";
        printThetas(thetas);
    }
}

vector<vector<float>> readCSV(string filename, vector<float>& target) {
    vector<vector<float>> data;
    ifstream file(filename);
    string line;
    
    // Read and discard the first line (feature names)
    getline(file, line);
    
    while (getline(file, line)) {
        stringstream ss(line);
        vector<float> row;
        string value;
        while (getline(ss, value, ',')) {
            row.push_back(stof(value));
        }
        target.push_back(row.back());
        row.pop_back();
        data.push_back(row);
    }
    return data;
}

int main() {
    string filename;
    cout << "Enter CSV file path: ";
    cin >> filename;

    vector<float> target;
    vector<vector<float>> data = readCSV(filename, target);
    int tl = data.size();
    int tc = data[0].size() + 1;
    
    vector<float> thetas(tc, 0.0);
    float lr;
    int epochs = 10;
    
    cout << "Enter learning rate: ";
    cin >> lr;
    
    gradientDescent(thetas, data, target, tc, tl, lr, epochs);
    
    cout << "Final Thetas: ";
    printThetas(thetas);
    
    return 0;
}
