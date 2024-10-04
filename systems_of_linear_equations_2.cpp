#include <iostream>

using namespace std;

const double EPSILON = 1e-10; 

void printMatrix(double **matrix, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n + 1; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}


// znalezienie indeksu elementu głównego w kolumnie
int findPivot(double **matrix, int k, int n) {
    int pivot_row = k;
    double max_val = abs(matrix[k][k]);

    for (int i = k + 1; i < n; ++i) {
        if (abs(matrix[i][k]) > max_val) {
            max_val = abs(matrix[i][k]);
            pivot_row = i;
        }
    }

    return pivot_row;
}



// zamiana wierszy w macierzy
void swapRows(double **matrix, int row1, int row2, int n) {
    for (int j = 0; j < n + 1; ++j) {
        double temp = matrix[row1][j];
        matrix[row1][j] = matrix[row2][j];
        matrix[row2][j] = temp;
    }
}


double* solveEquations(double **matrix, int n) {
    // eliminacja w przód
    for (int k = 0; k < n; ++k) {
        int pivot_row = findPivot(matrix, k, n);
        if (abs(matrix[pivot_row][k]) < EPSILON) {
            cerr << "singular matrix. " << endl;
            exit(1);
        }
        swapRows(matrix, k, pivot_row, n);

        for (int i = k + 1; i < n; ++i) {
            double factor = matrix[i][k] / matrix[k][k];
            for (int j = k; j < n + 1; ++j) {
                matrix[i][j] -= factor * matrix[k][j];
            }
        }
    }

    // macierz trójkątna
    double* solution = new double[n];
    for (int i = n - 1; i >= 0; --i) {
        solution[i] = matrix[i][n];
        for (int j = i + 1; j < n; ++j) {
            solution[i] -= matrix[i][j] * solution[j];
        }
        solution[i] /= matrix[i][i];
    }

    return solution;
}

int main() {
    int n = 3;
    double matrix[3][4] = {
        {5, -2, -1, -1},
        {3, -1, 2, 4},
        {-2, 1, 3, 5}
    };

    // konwersja macierzy do tablicy
    double **dynamic_matrix = new double*[n];
    for (int i = 0; i < n; ++i) {
        dynamic_matrix[i] = new double[n + 1];
        for (int j = 0; j < n + 1; ++j) {
            dynamic_matrix[i][j] = matrix[i][j];
        }
    }

    double* solution = solveEquations(dynamic_matrix, n);

    cout << "output: " << endl;
    for (int i = 0; i < n; ++i) {
        cout << "x" << i + 1 << " = " << solution[i] << endl;
    }

    for (int i = 0; i < n; ++i) {
        delete[] dynamic_matrix[i];
    }
    delete[] dynamic_matrix;
    delete[] solution;

    return 0;
}
