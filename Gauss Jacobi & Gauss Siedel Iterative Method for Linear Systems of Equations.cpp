#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, method;
    cout << "Enter size: ";
    cin >> n;
    
    double A[10][10], B[10], x[10], x_new[10];
    
    cout << "Enter matrix A:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];
    
    cout << "Enter vector B:\n";
    for (int i = 0; i < n; i++)
        cin >> B[i];
    
    cout << "Enter initial guess:\n";
    for (int i = 0; i < n; i++)
        cin >> x[i];
    
    cout << "Method (1-Jacobi, 2-Seidel): ";
    cin >> method;
    
    for (int iter = 0; iter < 100; iter++) {
        double error = 0;
        
        if (method == 1) { // Jacobi
            for (int i = 0; i < n; i++) {
                x_new[i] = B[i];
                for (int j = 0; j < n; j++)
                    if (i != j) x_new[i] -= A[i][j] * x[j];
                x_new[i] /= A[i][i];
            }
            for (int i = 0; i < n; i++) {
                error += abs(x_new[i] - x[i]);
                x[i] = x_new[i];
            }
        } else { // Seidel
            for (int i = 0; i < n; i++) {
                double old = x[i];
                x[i] = B[i];
                for (int j = 0; j < n; j++)
                    if (i != j) x[i] -= A[i][j] * x[j];
                x[i] /= A[i][i];
                B[i] = x[i];
                error += abs(x[i] - old);
            }
        }
        
        cout << "Iter " << iter + 1 << ": ";
        for (int i = 0; i < n; i++)
            cout << "x" << i + 1 << "=" << x[i] << " ";
        cout << "Error=" << error << "\n";
        
        if (error < 0.00001) break;
    }
    
    return 0;
}