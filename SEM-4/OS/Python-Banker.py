import numpy as np

NoOfProcess = 0
NoOfResources = 0
Allocation = []
MaxNeed = []
Need = []
MaxInstances = []
CurrentlyAvailable = []
AvailvleAfterGiving = []


def SimpleFill(matrix, rows, columns):
    for i in range(rows):
        temp = []
        for j in range(columns):
            temp1 = int(input())
            temp.append(temp1)
        matrix.append(temp)


def CalNeed(matrix, rows, columns):


    for i in range(rows):
        temp = []
        for j in range(columns):
            temp1 = MaxNeed[i][j] - Allocation[i][j]
            temp.append(temp1)
        matrix.append(temp)


def maxFill(matrix, columns):
    for i in range(columns):
        temp = int(input())
    matrix.append(temp)


def print2D(matrix, rows, columns):
    for i in range(rows):
        for j in range(columns):
            print(matrix[i][j], end="\t")
        print()


def print1D(matrix, columns):
    for j in range(columns):
        print(matrix[j], end="\t")
    print()


def CalCA():
    for j in range(NoOfResources):
        temp = 0
        for i in range(NoOfProcess):
            temp += Allocation[i][j]
        CurrentlyAvailable.append(MaxInstances[j] - temp)


def Banker():
    # Step 1: Calculate the currently available resources
    CalCA()
    # Step 2: Initialize the visited and answer vectors
    visited = [False]*NoOfProcess
    ans = []

    # Step 3: Repeat until all processes have been visited
    while len(ans) != NoOfProcess:
        # Step 4: Find a process that has not been visited and whose needs can be satisfied
        for i in range(NoOfProcess):
            if not visited[i]:
                check = True
                for j in range(NoOfResources):
                    if Need[i][j] > CurrentlyAvailable[j]:
                        check = False
                        break
                if check:
                    break

        # Step 5: If no such process is found, the system is in an unsafe state
        if i == NoOfProcess-1:
            print("The system is in an unsafe state.")
            return

        # Step 6: Mark the process as visited and add it to the answer vector
        visited[i] = True
        ans.append(i)

        # Step 7: Update the currently available resources
        for j in range(NoOfResources):
            CurrentlyAvailable[j] += Allocation[i][j]

    # Step 8: If all processes have been visited, the system is in a safe state
    print("The system is in a safe state.")
    print("Safe sequence: ", end="")
    for i in range(NoOfProcess):
        print(ans[i], end=" ")
    print()

print("Enter No of process")
NoOfProcess = int(input())
print("Enter No of Resources ")
NoOfResources = int(input())
print("Enter the max No. of instence for each resources")
maxFill(MaxInstances, NoOfResources)
print("Enter resource allocation for each of the process")
SimpleFill(Allocation, NoOfProcess, NoOfResources)
print("Enter max resource needed for each of the process")
SimpleFill(MaxNeed, NoOfProcess, NoOfResources)
CalNeed(Need, NoOfProcess, NoOfResources)
print("Allocation Matrix")
print2D(Allocation, NoOfProcess, NoOfResources)
Banker()
