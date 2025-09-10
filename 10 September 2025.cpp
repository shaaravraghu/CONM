#include <iostream>
#include <cmath>
using namespace std;

// Function to calculate factorial
int factorial(int n) {
    return (n <= 1) ? 1 : n * factorial(n - 1);
}

// Function to construct the forward difference table
void constructForwardDifference(double diff[][20], int n) {
    for (int i = 1; i < n; i++) {// controls number of rows and max n rows (with one row for y)
        for (int j = 0; j < n - i; j++) {// takes value of the difference
            diff[j][i] = diff[j + 1][i - 1] - diff[j][i - 1]; // difference of consecutive terms
        }
    }
}

// Function to apply Newton's Forward Interpolation
double newtonForward(double x[], double diff[][20], int n, double value) {
    double h = x[1] - x[0]; // Assuming uniform spacing
    double u = (value - x[0]) / h;
    double result = diff[0][0];

    for (int i = 1; i < n; i++) {
        double term = diff[0][i];
        for (int j = 0; j < i; j++) {
            term *= (u - j);
        }
        term /= factorial(i);
        result += term;
    }
    return result;
}

int main() {
    int n;
    cout << "Enter number of data points: ";
    cin >> n;

    double x[20], y[20], diff[20][20];// differnce values, row number: row 0: y, row1: y1 .....

    cout << "Enter x values:\n";
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    cout << "Enter y values:\n";
    for (int i = 0; i < n; i++) {
        cin >> y[i];
        diff[i][0] = y[i]; // First column is y values
    }

    constructForwardDifference(diff, n);

    double value;
    cout << "Enter the value to interpolate: ";
    cin >> value;

    double result = newtonForward(x, diff, n, value);
    cout << "Interpolated value at " << value << " is " << result << endl;

    return 0;
}
