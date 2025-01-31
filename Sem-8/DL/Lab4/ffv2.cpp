#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <cmath>
#include <sstream>
#include <random>
#include <algorithm>

using namespace std;

// Function to compute Pearson correlation coefficient
float computeCorrelation(const vector<float>& x, const vector<float>& y) {
    int n = x.size();
    float sum_x = 0, sum_y = 0, sum_xy = 0;
    float sum_x2 = 0, sum_y2 = 0;
    
    for (int i = 0; i < n; i++) {
        sum_x += x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
        sum_x2 += x[i] * x[i];
        sum_y2 += y[i] * y[i];
    }
    
    float numerator = (n * sum_xy - sum_x * sum_y);
    float denominator = sqrt((n * sum_x2 - sum_x * sum_x) * (n * sum_y2 - sum_y * sum_y));
    
    if (denominator == 0) return 0; // Prevent division by zero
    return numerator / denominator;
}

// Read CSV file and extract data
void readCSV(const string& filename, vector<vector<float>>& features, vector<float>& target) {
    ifstream file(filename);
    string line;
    getline(file, line); // Skip header line

    while (getline(file, line)) {
        stringstream ss(line);
        vector<float> row;
        string value;
        
        while (getline(ss, value, ',')) {
            row.push_back(stof(value));
        }
        
        target.push_back(row.back()); // Last column is 'y'
        row.pop_back(); // Remove 'y' from features
        features.push_back(row);
    }
}

// Generate random weights
void initializeWeights(map<pair<pair<int, int>, pair<int, int>>, float>& weights, int layerSize, int numLayers) {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<float> dist(-1.0, 1.0);
    
    for (int i = 0; i < numLayers - 1; i++) {
        for (int j = 0; j < layerSize; j++) {
            for (int k = 0; k < layerSize; k++) {
                weights[{{i, j}, {i + 1, k}}] = dist(gen);
            }
        }
    }
}

// Forward propagation
void forwardPass(vector<vector<float>>& neuron, int layers, map<pair<pair<int, int>, pair<int, int>>, float>& weights, vector<float>& bias) {
    for (int i = 0; i < layers - 1; i++) {
        for (int j = 0; j < neuron[i+1].size(); j++) {
            float sum = 0;
            for (int k = 0; k < neuron[i].size(); k++) {
                sum += neuron[i][k] * weights[{{i, k}, {i + 1, j}}];
            }
            sum += bias[i + 1];
            neuron[i + 1][j] = 1 / (1 + exp(-sum)); // Sigmoid activation
        }
    }
}

int main() {
    string filename = "data.csv";
    vector<vector<float>> features;
    vector<float> target;
    
    readCSV(filename, features, target);
    int numFeatures = features[0].size();
    
    // Prompt user for the number of hidden layers
    int numLayers;
    cout << "Enter the number of hidden layers (including input and output layers): ";
    cin >> numLayers;

    // Compute correlation with y and select features
    vector<int> selectedFeatures;
    cout << "Correlation Analysis: " << endl;
    for (int i = 0; i < numFeatures; i++) {
        vector<float> column;
        for (auto& row : features) column.push_back(row[i]);
        
        float correlation = computeCorrelation(column, target);
        cout << "Feature " << i << " Correlation: " << correlation << endl;
        
        if (abs(correlation) > 0.5) {
            selectedFeatures.push_back(i);
            cout << "Feature " << i << " selected." << endl;
        }
    }

    cout << "Selected Features: ";
    for (int idx : selectedFeatures) {
        cout << idx << " ";
    }
    cout << endl;

    int layerSize = selectedFeatures.size();
    
    // Initialize weights
    map<pair<pair<int, int>, pair<int, int>>, float> weights;
    initializeWeights(weights, layerSize, numLayers);
    
    // Bias initialization
    vector<float> bias(numLayers, 0.5); // Example bias value
    
    cout << "\nWeights Initialization: " << endl;
    for (const auto& weight : weights) {
        cout << "Weight [Layer " << weight.first.first.first << "->" 
             << weight.first.first.second << " to Layer "
             << weight.first.second.first << "->" 
             << weight.first.second.second << "] = "
             << weight.second << endl;
    }
    
    // Forward propagation for each input
    for (auto& row : features) {
        vector<vector<float>> neuron(numLayers, vector<float>(layerSize, 0));
        for (int i = 0; i < layerSize; i++) {
            neuron[0][i] = row[selectedFeatures[i]]; // Use selected features as input
        }
        forwardPass(neuron, numLayers, weights, bias);
        
        cout << "\nPrediction for this row: " << neuron.back()[0] << endl; // Output prediction
    }
    
    return 0;
}
