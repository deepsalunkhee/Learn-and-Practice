#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

using namespace std;

// Mean Squared Error Function
float mse(float w, float b, vector<float> x_values, vector<float> y_values, int n) {
    float sum = 0;
    for (int i = 0; i < n; i++) {
        float y_pred = x_values[i] * w + b;
        sum += pow((y_values[i] - y_pred), 2);
    }
    return sum / (2 * n);
}

// Stochastic Gradient Descent
void sgd(float w, float b, float neta, vector<float> x_values, vector<float> y_values, int n) {
    for (int i = 0; i < n; i++) {
        float y_pred = x_values[i] * w + b;
        float dw = -1 * (y_values[i] - y_pred) * x_values[i];
        float db = -1 * (y_values[i] - y_pred);
        w -= neta * dw;
        b -= neta * db;
    }
    cout << "SGD: w = " << w << ", b = " << b << ", MSE = " << mse(w, b, x_values, y_values, n) << endl;
}

// Mini Batch Gradient Descent with Momentum
void mgd(float w, float b, float neta, float beta, vector<float> x_values, vector<float> y_values, int n) {
    float v_w = 0, v_b = 0;
    for (int i = 0; i < n; i++) {
        float y_pred = x_values[i] * w + b;
        float dw = -1 * (y_values[i] - y_pred) * x_values[i];
        float db = -1 * (y_values[i] - y_pred);
        v_w = beta * v_w + neta * dw;
        v_b = beta * v_b + neta * db;
        w -= v_w;
        b -= v_b;
    }
    cout << "MGD: w = " << w << ", b = " << b << ", MSE = " << mse(w, b, x_values, y_values, n) << endl;
}

// Adaptive Gradient Descent
void agd(float w, float b, float neta, vector<float> x_values, vector<float> y_values, int n) {
    float alpha_w = 0, alpha_b = 0, epsilon = 1e-8;
    for (int i = 0; i < n; i++) {
        float y_pred = x_values[i] * w + b;
        float dw = -1 * (y_values[i] - y_pred) * x_values[i];
        float db = -1 * (y_values[i] - y_pred);
        alpha_w += pow(dw, 2);
        alpha_b += pow(db, 2);
        w -= (neta / sqrt(alpha_w + epsilon)) * dw;
        b -= (neta / sqrt(alpha_b + epsilon)) * db;
    }
    cout << "AGD: w = " << w << ", b = " << b << ", MSE = " << mse(w, b, x_values, y_values, n) << endl;
}

// Adam Gradient Descent
void adam(float w, float b, float neta, float beta1, float beta2, vector<float> x_values, vector<float> y_values, int n) {
    float m_w = 0, m_b = 0, v_w = 0, v_b = 0, epsilon = 1e-8;
    for (int i = 0; i < n; i++) {
        float y_pred = x_values[i] * w + b;
        float dw = -1 * (y_values[i] - y_pred) * x_values[i];
        float db = -1 * (y_values[i] - y_pred);
        m_w = beta1 * m_w + (1 - beta1) * dw;
        m_b = beta1 * m_b + (1 - beta1) * db;
        v_w = beta2 * v_w + (1 - beta2) * pow(dw, 2);
        v_b = beta2 * v_b + (1 - beta2) * pow(db, 2);
        w -= (neta * m_w) / (sqrt(v_w) + epsilon);
        b -= (neta * m_b) / (sqrt(v_b) + epsilon);
    }
    cout << "Adam: w = " << w << ", b = " << b << ", MSE = " << mse(w, b, x_values, y_values, n) << endl;
}

int main() {
    float w = 0.5, b = 0.5, neta = 0.01, beta1 = 0.9, beta2 = 0.999, beta = 0.9;
    vector<float> x_values = {1, 2, 3, 4, 5};
    vector<float> y_values = {2.2, 2.8, 3.6, 4.5, 5.1};
    int n = x_values.size();
    
    cout << "Initial MSE: " << mse(w, b, x_values, y_values, n) << endl;
    
    sgd(w, b, neta, x_values, y_values, n);
    mgd(w, b, neta, beta, x_values, y_values, n);
    agd(w, b, neta, x_values, y_values, n);
    adam(w, b, neta, beta1, beta2, x_values, y_values, n);
    
    return 0;
}
