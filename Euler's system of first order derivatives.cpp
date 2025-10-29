#include <iostream>
#include <cmath>
using namespace std;

// Example: y'' = f(x,y,y',z,z')
//          z'' = g(x,y,y',z,z')
double f(double x, double y, double v, double z, double w){
	// v := y'; w := z'
    // define y'' = f(...)
    // example: y'' = x*x + sin(y) + cos(z)  (you can change)
    return x*x + sin(y) + cos(z);
}

double g(double x, double y, double v, double z, double w){
	// v := y'; w := z'
    // define z'' = g(...)
    // example: z'' = exp(-x*x) + sin(y*y) + exp(-z*z)  (you can change)
    return exp(-x*x) + sin(y*y) + exp(-z*z);
}

int main(){
    int n;
    cout << "enter number of intervals: ";
    cin >> n;

    double x0, xn;
    cout << "enter range (x0 xn): ";
    cin >> x0 >> xn;

    double y0, v0; // y and y' at x0
    cout << "enter y(x0) and y'(x0): ";
    cin >> y0 >> v0;

    double z0, w0; // z and z' at x0
    cout << "enter z(x0) and z'(x0): ";
    cin >> z0 >> w0;

    double h = (xn - x0) / n;
    double x = x0;

    // state variables:
    double y = y0, v = v0; // y, y'
    double z = z0, w = w0; // z, z'

    cout << "x\t y\t v(y')\t z\t w(z')\n";
    cout << x << "\t" << y << "\t" << v << "\t" << z << "\t" << w << "\n";

    for (int i = 0; i < n; ++i) {
        // Euler updates for the system
        double y_next = y + h * v;                     // y_{n+1} = y_n + h*y'_n
        double v_next = v + h * f(x, y, v, z, w);      // v_{n+1} = v_n + h * f(...)
        double z_next = z + h * w;                     // z_{n+1} = z_n + h*z'_n
        double w_next = w + h * g(x, y, v, z, w);      // w_{n+1} = w_n + h * g(...)

        // advance
        x += h;
        y = y_next; v = v_next;
        z = z_next; w = w_next;

        cout << x << "\t" << y << "\t" << v << "\t" << z << "\t" << w << "\n";
    }

    return 0;
}
