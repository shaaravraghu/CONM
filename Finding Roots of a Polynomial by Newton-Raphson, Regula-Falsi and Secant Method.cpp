#include <iostream>
#include <cmath>

// Function f(x) = x^3 - 4x - 9 (example equation)
double f(double x) {
    return x*x*x - 4*x - 9;
}

// Derivative f'(x) = 3x^2 - 4 (for Newton-Raphson method)
double f_derivative(double x) {
    return 3*x*x - 4;
}

// Newton-Raphson Method
// Formula: x(n+1) = x(n) - f(x(n))/f'(x(n))
double newtonRaphson(double x0, double tolerance, int maxIterations) {
    double x = x0;
    int iteration = 0;
    
    std::cout << "\nNewton-Raphson Method:\n";
    std::cout << "Formula: x(n+1) = x(n) - f(x(n))/f'(x(n))\n";
    std::cout << "Iter\tx\t\tf(x)\t\tf'(x)\t\tError\n";
    
    while (iteration < maxIterations) {
        double fx = f(x);
        double fpx = f_derivative(x);
        
        if (fpx == 0) {
            std::cout << "Error: Derivative is zero. Cannot continue.\n";
            return x;
        }
        
        double x_new = x - fx/fpx;
        double error = x_new - x;
        
        std::cout << iteration << "\t" << x << "\t" << fx << "\t" << fpx << "\t" << error << "\n";
        
        if (fabs(error) < tolerance) {
            std::cout << "Root found: " << x_new << " after " << iteration + 1 << " iterations\n";
            return x_new;
        }
        
        x = x_new;
        iteration++;
    }
    
    std::cout << "Maximum iterations reached. Approximate root: " << x << "\n";
    return x;
}

// Regula-Falsi (False Position) Method
// Formula: x(n+1) = x0 - f(x0) * (x1 - x0) / (f(x1) - f(x0))
double regulaFalsi(double x0, double x1, double tolerance, int maxIterations) {
    double a = x0, b = x1;
    int iteration = 0;
    
    std::cout << "\nRegula-Falsi Method:\n";
    std::cout << "Formula: x = a - f(a) * (b - a) / (f(b) - f(a))\n";
    std::cout << "Iter\ta\t\tb\t\tc\t\tf(a)\t\tf(b)\t\tf(c)\t\tError\n";
    
    if (f(a) * f(b) >= 0) {
        std::cout << "Error: f(a) and f(b) must have opposite signs for Regula-Falsi method\n";
        std::cout << "f(" << a << ") = " << f(a) << ", f(" << b << ") = " << f(b) << "\n";
        std::cout << "Cannot proceed with Regula-Falsi method. Choose different interval.\n";
        return 0; // Return 0 to indicate failure
    }
    
    double c_prev = a;
    
    while (iteration < maxIterations) {
        double fa = f(a);
        double fb = f(b);
        
        // Apply Regula-Falsi formula
        double c = a - fa * (b - a) / (fb - fa);
        double fc = f(c);
        
        double error = fabs(c - c_prev);
        
        std::cout << iteration << "\t" << a << "\t" << b << "\t" << c << "\t" 
                  << fa << "\t" << fb << "\t" << fc << "\t" << error << "\n";
        
        if (fabs(fc) < tolerance || error < tolerance) {
            std::cout << "Root found: " << c << " after " << iteration + 1 << " iterations\n";
            std::cout << "Function value at root: f(" << c << ") = " << fc << "\n";
            std::cout << "Final error between iterations: " << error << "\n";
            return c;
        }
        
        // Update interval based on sign of f(c)
        if (fa * fc < 0) {
            b = c;
        } else {
            a = c;
        }
        
        c_prev = c;
        iteration++;
    }
    
    double final_root = a - f(a) * (b - a) / (f(b) - f(a));
    std::cout << "Maximum iterations reached. Approximate root: " << final_root << "\n";
    return final_root;
}

// Secant Method
// Formula: x(n+1) = x(n) - f(x(n)) * (x(n) - x(n-1)) / (f(x(n)) - f(x(n-1)))
double secantMethod(double x0, double x1, double tolerance, int maxIterations) {
    double x_prev = x0;
    double x_curr = x1;
    int iteration = 0;
    
    std::cout << "\nSecant Method:\n";
    std::cout << "Formula: x(n+1) = x(n) - f(x(n)) * (x(n) - x(n-1)) / (f(x(n)) - f(x(n-1)))\n";
    std::cout << "Iter\tx(n-1)\t\tx(n)\t\tf(x(n-1))\tf(x(n))\t\tx(n+1)\t\tError\n";
    
    while (iteration < maxIterations) {
        double f_prev = f(x_prev);
        double f_curr = f(x_curr);
        
        if (f_curr - f_prev == 0) {
            std::cout << "Error: Division by zero. Cannot continue.\n";
            return x_curr;
        }
        
        // Apply Secant formula
        double x_new = x_curr - f_curr * (x_curr - x_prev) / (f_curr - f_prev);
        double error = fabs(x_new - x_curr);
        
        std::cout << iteration << "\t" << x_prev << "\t" << x_curr << "\t" 
                  << f_prev << "\t" << f_curr << "\t" << x_new << "\t" << error << "\n";
        
        if (error < tolerance) {
            std::cout << "Root found: " << x_new << " after " << iteration + 1 << " iterations\n";
            return x_new;
        }
        
        x_prev = x_curr;
        x_curr = x_new;
        iteration++;
    }
    
    std::cout << "Maximum iterations reached. Approximate root: " << x_curr << "\n";
    return x_curr;
}

// Function to display the equation being solved
void displayEquation() {
    std::cout << "Solving equation: f(x) = x^3 - 4x - 9 = 0\n";
    std::cout << "Derivative: f'(x) = 3x^2 - 4\n";
    std::cout << "==========================================\n";
}

int main() {
    displayEquation();
    
    // Get user input for parameters
    double tolerance;
    int maxIterations;
    double x0, x1, a, b;
    
    std::cout << "Enter tolerance (e.g., 0.0001): ";
    std::cin >> tolerance;
    
    std::cout << "Enter maximum iterations (e.g., 50): ";
    std::cin >> maxIterations;
    
    std::cout << "\n--- Newton-Raphson Method Parameters ---\n";
    std::cout << "Enter initial guess x0: ";
    std::cin >> x0;
    
    std::cout << "\n--- Secant Method Parameters ---\n";
    std::cout << "Enter first point x0: ";
    std::cin >> x0;
    std::cout << "Enter second point x1: ";
    std::cin >> x1;
    
    std::cout << "\n--- Regula-Falsi Method Parameters ---\n";
    std::cout << "Enter lower bound a: ";
    std::cin >> a;
    std::cout << "Enter upper bound b: ";
    std::cin >> b;
    
    // Display user inputs
    std::cout << "\n==========================================\n";
    std::cout << "USER INPUTS:\n";
    std::cout << "Tolerance: " << tolerance << "\n";
    std::cout << "Maximum iterations: " << maxIterations << "\n";
    std::cout << "Newton-Raphson initial guess: " << x0 << "\n";
    std::cout << "Secant method points: " << x0 << ", " << x1 << "\n";
    std::cout << "Regula-Falsi interval: [" << a << ", " << b << "]\n";
    std::cout << "==========================================\n\n";
    
    // Check if Regula-Falsi interval is valid
    if (f(a) * f(b) >= 0) {
        std::cout << "WARNING: f(a) and f(b) have the same sign for Regula-Falsi!\n";
        std::cout << "f(" << a << ") = " << f(a) << "\n";
        std::cout << "f(" << b << ") = " << f(b) << "\n";
        std::cout << "Regula-Falsi method will fail. Consider choosing different values.\n\n";
    }
    
    char choice;
    std::cout << "Do you want to proceed with all methods? (y/n): ";
    std::cin >> choice;
    
    if (choice == 'y' || choice == 'Y') {
        // Newton-Raphson Method
        double root1 = newtonRaphson(x0, tolerance, maxIterations);
        
        // Regula-Falsi Method
        double root2 = regulaFalsi(a, b, tolerance, maxIterations);
        
        // Secant Method
        double root3 = secantMethod(x0, x1, tolerance, maxIterations);
        
        std::cout << "\n==========================================\n";
        std::cout << "SUMMARY OF RESULTS:\n";
        std::cout << "Newton-Raphson root: " << root1 << "\n";
        std::cout << "Regula-Falsi root: " << root2 << "\n";
        std::cout << "Secant Method root: " << root3 << "\n";
        std::cout << "==========================================\n";
        
        // Verify results
        std::cout << "\nVerification:\n";
        std::cout << "f(" << root1 << ") = " << f(root1) << "\n";
        std::cout << "f(" << root2 << ") = " << f(root2) << "\n";
        std::cout << "f(" << root3 << ") = " << f(root3) << "\n";
    } else {
        std::cout << "Program terminated by user.\n";
    }
    
    return 0;
}