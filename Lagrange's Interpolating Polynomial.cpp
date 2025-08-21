#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, c;
    int n;
    
    cout << "Enter interval [a, b]: ";
    cin >> a >> b;
    cout << "Enter number of interpolation points: ";
    cin >> n;
    cout << "Enter point c to evaluate: ";
    cin >> c;
    
    double x[n], y[n];
    
    // Generate equally spaced points in [a,b]
    for(int i = 0; i < n; i++) {
        x[i] = a + i * (b - a) / (n - 1);
        y[i] = sin(x[i]);
    }
    
    // Lagrange interpolation at point c
    double result = 0;
    for(int i = 0; i < n; i++) {
        double term = y[i];
        for(int j = 0; j < n; j++) {
            if(i != j) {
                term *= (c - x[j]) / (x[i] - x[j]);
            }
        }
        result += term;
    }
    
    cout << "Interpolated value at " << c << ": " << result << endl;
    cout << "Actual sin(" << c << "): " << sin(c) << endl;
    cout << "Error: " << abs(result - sin(c)) << endl;
    
    return 0;
}