#include <iostream>
#include <cmath>
using namespace std;

int dim;
const double EPSILON = 1e-10;

// Function to check invertibility and find inverse using Gauss-Jordan method
// Returns: 0 = not invertible, 1 = invertible and inverse found
int find_inverse_gauss_jordan(double matrix[][100], double inverse[][100]) {

    // Create augmented matrix [A|I]
    double augmented[100][200];
    
    // Initialize augmented matrix
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            augmented[i][j] = matrix[i][j];           // Original matrix
            augmented[i][j + dim] = (i == j) ? 1.0 : 0.0;  // Identity matrix
        }
    }
    
    // Gauss-Jordan elimination without row swapping
    for (int col = 0; col < dim; col++) {
        // Find a non-zero pivot in the current column
        int pivot_row = -1;
        for (int row = 0; row < dim; row++) {
            if (abs(augmented[row][col]) > EPSILON) {
                pivot_row = row;
                break;
            }
        }
        
        // Check if no pivot found (matrix is singular - not invertible)
        if (pivot_row == -1) {
            return 0;  // Matrix is not invertible (rank < dim)
        }
        
        // Normalize the pivot row (make pivot element = 1)
        double pivot = augmented[pivot_row][col];
        for (int j = 0; j < 2 * dim; j++) {
            augmented[pivot_row][j] /= pivot;
        }
        
        // Eliminate all other elements in this column using row operations
        for (int row = 0; row < dim; row++) {
            if (row != pivot_row && abs(augmented[row][col]) > EPSILON) {
                // Calculate the elimination factor
                double factor = augmented[row][col] / augmented[pivot_row][col];
                
                // Perform row operation: row = row - factor * pivot_row
                for (int j = 0; j < 2 * dim; j++) {
                    augmented[row][j] -= factor * augmented[pivot_row][j];
                }
            }
        }
    }
    
    // Extract inverse matrix from augmented matrix
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            inverse[i][j] = augmented[i][j + dim];
        }
    }
    
    return 1;  // Matrix is invertible and inverse found
}

// Function to print matrix
void print_matrix(double matrix[][100], string name) {
    cout << "\n" << name << ":\n";
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << "\n";
    }
}

// Function to verify the inverse by multiplying A * A^(-1)
void verify_inverse(double original[][100], double inverse[][100]) {
    double result[100][100];
    
    // Multiply original matrix with its inverse
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            result[i][j] = 0;
            for (int k = 0; k < dim; k++) {
                result[i][j] += original[i][k] * inverse[k][j];
            }
        }
    }
    
    cout << "\nVerification (A * A^(-1) should be Identity Matrix):\n";
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            // Round very small numbers to 0 for cleaner display
            if (abs(result[i][j]) < EPSILON) {
                result[i][j] = 0;
            }
            cout << result[i][j] << "\t";
        }
        cout << "\n";
    }
}

int main() {
    cout << "Enter the dimension of your matrix: ";
    cin >> dim;
    
    if (dim <= 0 || dim > 100) {
        cout << "Invalid dimension! Please enter a value between 1 and 100.\n";
        return 1;
    }
    
    double matrix[100][100];
    double inverse_matrix[100][100];
    
    cout << "\nEnter the matrix elements:\n";
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            cout << "Enter element [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matrix[i][j];
        }
    }
    
    // Print original matrix
    print_matrix(matrix, "Original Matrix");
    
    // Find inverse using Gauss-Jordan method (also checks invertibility)
    int result = find_inverse_gauss_jordan(matrix, inverse_matrix);
    
    if (result == 0) {
        cout << "\nMatrix is not invertible (rank < " << dim << ")!\n";
        cout << "The matrix is singular and does not have an inverse.\n";
        return 0;
    }
    
    cout << "\nMatrix is invertible (rank = " << dim << ")!\n";
    print_matrix(inverse_matrix, "Inverse Matrix");
    verify_inverse(matrix, inverse_matrix);
    
    return 0;
}