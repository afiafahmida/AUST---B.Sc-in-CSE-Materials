//inverse

#include<bits/stdc++.h>
using namespace std;

void printMatrix(const vector<vector<double>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << "\n";
    }
}

void GaussJordanInverse(vector<vector<double>>& matrix) {
    int n = matrix.size();
    vector<vector<double>> identity(n, vector<double>(n, 0.0));
    for (int i = 0; i < n; ++i) {
        identity[i][i] = 1.0;
    }

    // Gauss-Jordan Elimination
    for (int i = 0; i < n; ++i) {
        double pivot = matrix[i][i];
        if (fabs(pivot) < 1e-9) {
            cout << "Pivot element is too close to zero. Unable to proceed." << endl;
            return;
        }

        for (int j = 0; j < n; ++j) {
            matrix[i][j] /= pivot;
            identity[i][j] /= pivot;
        }

        for (int k = 0; k < n; ++k) {
            if (k != i) {
                double factor = matrix[k][i];
                for (int j = 0; j < n; ++j) {
                    matrix[k][j] -= factor * matrix[i][j];
                    identity[k][j] -= factor * identity[i][j];
                }
            }
        }
    }

    matrix = identity;
}

int main() {
    int n;
    cout << "Enter the number of unknown variables: ";
    cin >> n;

    vector<vector<double>> matrix(n, vector<double>(n));
    cout << "Enter the augmented matrix of coefficients: " << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    // Create augmented matrix (augmented with identity matrix) to perform Gauss-Jordan
    for (int i = 0; i < n; ++i) {
        matrix[i].resize(2 * n, 0.0);
        matrix[i][n + i] = 1.0;
    }

    cout << "\nAugmented Matrix before Gauss-Jordan Inverse:\n";
    printMatrix(matrix);

    GaussJordanInverse(matrix);

    cout << "\nAugmented Matrix after Gauss-Jordan Inverse:\n";
    printMatrix(matrix);

    cout << "\nInverse Matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = n; j < 2 * n; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << "\n";
    }

    return 0;
}

