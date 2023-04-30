const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let NoOfProcess, NoOfResources;
let Allocation = [], MaxNeed = [], Need = [], MaxInstances = [];
let CurrentlyAvailable = [], AvailvleAfterGiving = [];

function SimpleFill(matrix, rows, columns) {
  return new Promise((resolve, reject) => {
    let row = 0;

    const handleLine = (line) => {
      const elements = line.trim().split(/\s+/).map(Number);
      if (elements.length !== columns) {
        reject(new Error(`Invalid number of columns in line ${row + 1}`));
        rl.close();
      }
      matrix.push(elements);
      row++;
      if (row === rows) {
        resolve();
      }
    };

    rl.on('line', handleLine);
  });
}

function CalNeed(matrix, rows, columns) {
  for (let i = 0; i < rows; i++) {
    let temp = [];

    for (let j = 0; j < columns; j++) {
      let temp1 = MaxNeed[i][j] - Allocation[i][j];
      temp.push(temp1);
    }
    matrix.push(temp);
  }
}

function maxFill(matrix, columns) {
  return new Promise((resolve, reject) => {
    rl.on('line', (line) => {
      const elements = line.trim().split(/\s+/).map(Number);
      if (elements.length !== columns) {
        reject(new Error(`Invalid number of columns in line ${row + 1}`));
        rl.close();
      }
      matrix.push(elements);
      resolve();
    });
  });
}

function print2D(matrix, rows, columns) {
  for (let i = 0; i < rows; i++) {
    let rowString = '';
    for (let j = 0; j < columns; j++) {
      rowString += matrix[i][j] + '\t';
    }
    console.log(rowString);
  }
}

function print1D(matrix, columns) {
  let rowString = '';
  for (let j = 0; j < columns; j++) {
    rowString += matrix[j] + '\t';
  }
  console.log(rowString);
}

function CalCA() {
  for (let j = 0; j < NoOfResources; j++) {
    let temp = 0;
    for (let i = 0; i < NoOfProcess; i++) {
      temp += Allocation[i][j];
    }
    CurrentlyAvailable.push(MaxInstances[j] - temp);
  }
}

function Banker() {
  // Step 1: Calculate the currently available resources
  CalCA();

  // Step 2: Initialize the visited and answer vectors
  let visited = new Array(NoOfProcess).fill(false);
  let ans = [];

  // Step 3: Repeat until all processes have been visited
  while (ans.length !== NoOfProcess) {
    // Step 4: Find a process that has not been visited and whose needs can be satisfied
    let i;
    for (i = 0; i < NoOfProcess; i++) {
      if (!visited[i]) {
        let check = true;
        for (let j = 0; j < NoOfResources; j++) {
          if (Need[i][j] > CurrentlyAvailable[j]) {
            check = false;
            break;
          }
        }
        if (check) {
          break;
        }
      }
   // User input
const readline = require("readline");
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let NoOfProcess, NoOfResources;
let Allocation = [], MaxNeed = [], Need = [];
let MaxInstances = [], CurrentlyAvailable = [], AvailvleAfterGiving = [];

// Function to fill a matrix
function fillMatrix(matrix, rows, columns) {
    for (let i = 0; i < rows; i++) {
        let temp = [];

        for (let j = 0; j < columns; j++) {
            let temp1 = parseInt(prompt(`Enter value for matrix[${i}][${j}]: `));
            temp.push(temp1);
        }
        matrix.push(temp);
    }
}

// Function to calculate Need matrix
function calculateNeedMatrix() {
    for (let i = 0; i < NoOfProcess; i++) {
        let temp = [];

        for (let j = 0; j < NoOfResources; j++) {
            let temp1 = MaxNeed[i][j] - Allocation[i][j];
            temp.push(temp1);
        }
        Need.push(temp);
    }
}

// Function to print a matrix
function printMatrix(matrix, rows, columns) {
    for (let i = 0; i < rows; i++) {
        let rowString = "";

        for (let j = 0; j < columns; j++) {
            rowString += matrix[i][j] + "\t";
        }
        console.log(rowString);
    }
}

// Function to calculate the Currently Available vector
function calculateCAVector() {
    for (let j = 0; j < NoOfResources; j++) {
        let temp = 0;
        for (let i = 0; i < NoOfProcess; i++) {
            temp += Allocation[i][j];
        }
        CurrentlyAvailable.push(MaxInstances[j] - temp);
    }
}

// Function to perform Banker's Algorithm
function bankerAlgorithm(processes, available, maxNeed, currentAlloc) {
    const n = processes.length;
    const m = available.length;
  
    // Calculate need matrix
    const need = new Array(n);
    for (let i = 0; i < n; i++) {
      need[i] = new Array(m);
      for (let j = 0; j < m; j++) {
        need[i][j] = maxNeed[i][j] - currentAlloc[i][j];
      }
    }
  
    // Initialize finish array
    const finish = new Array(n).fill(false);
  
    // Initialize work array
    let work = [...available];
  
    // Initialize safe sequence array
    const safeSequence = [];
  
    // Loop until all processes are finished or no safe sequence is found
    while (safeSequence.length < n) {
      let foundProcess = false;
      for (let i = 0; i < n; i++) {
        if (!finish[i] && checkProcess(i, work, need)) {
          foundProcess = true;
          finish[i] = true;
          safeSequence.push(processes[i]);
          for (let j = 0; j < m; j++) {
            work[j] += currentAlloc[i][j];
          }
          break;
        }
      }
      if (!foundProcess) {
        // No process found that can be executed, the system is not in a safe state
        return null;
      }
    }
  
    // All processes have finished successfully, return the safe sequence
    return safeSequence;
  }
  
  function checkProcess(processIndex, work, need) {
    const m = work.length;
    for (let j = 0; j < m; j++) {
      if (need[processIndex][j] > work[j]) {
        return false;
      }
    }
    return true;
  }
}}} 