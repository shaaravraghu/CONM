#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter matrix dimension: ";
    cin >> n;
    double A[10][10], L[10][10] = {0}, U[10][10] = {0};
    
    cout << "Enter matrix elements:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];
    
    for (int i = 0; i < n; i++) {
        L[i][i] = 1;
        for (int k = i; k < n; k++) {
            double sum = 0;
            for (int j = 0; j < i; j++) sum += L[i][j] * U[j][k];
            U[i][k] = A[i][k] - sum;
        }
        for (int k = i + 1; k < n; k++) {
            double sum = 0;
            for (int j = 0; j < i; j++) sum += L[k][j] * U[j][i];
            L[k][i] = (A[k][i] - sum) / U[i][i];
        }
    }
    
    cout << "L matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << L[i][j] << " ";
        cout << "\n";
    }
    
    cout << "U matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << U[i][j] << " ";
        cout << "\n";
    }
    
    return 0;
}