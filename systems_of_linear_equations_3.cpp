#include <iostream>
#include <cmath>
#include <time.h>
#include <cstdlib>

using namespace std;

clock_t start, stop;
double czas1, czas2;

const int N = 10;

//-----------------METODA LU---------------------

void LU(double A[N][N], double L[N][N], double U[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int k = i; k < N; k++) {
            double sum = 0;
            for (int j = 0; j < i; j++)
                sum += (L[i][j] * U[j][k]);
            U[i][k] = A[i][k] - sum;
        }

        for (int k = i; k < N; k++) {
            if (i == k)
                L[i][i] = 1;
            else {
                double sum = 0;
                for (int j = 0; j < i; j++)
                    sum += (L[k][j] * U[j][i]);
                L[k][i] = (A[k][i] - sum) / U[i][i];
            }
        }
    }
}


void solveLU(double A[N][N], double b[N], double x[N]) {
    double L[N][N] = {0};
    double U[N][N] = {0};

    LU(A, L, U);

    // Forward substitution to solve L*y = b
    double y[N] = {0};
    for (int i = 0; i < N; i++) {
        double sum = 0;
        for (int j = 0; j < i; j++)
            sum += L[i][j] * y[j];
        y[i] = b[i] - sum;
    }

    // Backward substitution to solve U*x = y
    for (int i = N - 1; i >= 0; i--) {
        double sum = 0;
        for (int j = i + 1; j < N; j++)
            sum += U[i][j] * x[j];
        x[i] = (y[i] - sum) / U[i][i];
    }
}

//---------METODA CHOLESKIEGO--------------------


void cholesky(double A[N][N], double b[N], double x[N]) {
    double L[N][N] = {}; 

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= i; ++j) {
            double sum = 0.0;
            for (int k = 0; k < j; ++k) {
                sum += L[i][k] * L[j][k];
            }
           
            L[i][j] = sqrt(A[i][i] - sum);
            L[i][j] = (A[i][j] - sum) / L[j][j];

        }
    }

    // L * y = b 
    double y[N] = {};
    for (int i = 0; i < N; ++i) {
        double sum = 0.0;
        for (int j = 0; j < i; ++j) {
            sum += L[i][j] * y[j];
        }
        y[i] = (b[i] - sum) / L[i][i];
    }

    // L^T * x = y 
    for (int i = N - 1; i >= 0; --i) {
        double sum = 0.0;
        for (int j = i + 1; j < N; ++j) {
            sum += L[j][i] * x[j];
        }
        x[i] = (y[i] - sum) / L[i][i];
    }
}



int main() {
    double A[N][N] = {
    {10,1,2,3,4,5,6,7,8,9},
    {1,20,1,2,3,4,5,6,7,8},
    {2,1,30,1,2,3,4,5,6,7},
    {3,2,1,40,1,2,3,4,5,6},
    {4,3,2,1,0,1,2,3,4,5},
    {5,4,3,2,1,60,1,2,3,4},
    {6,5,4,3,2,1,70,1,2,3},
    {7,6,5,4,3,2,1,80,1,2},
    {8,7,6,5,4,3,2,1,90,1},
    {9,8,7,6,5,4,3,2,1,100}
};

double b[N] = {55,56,57,58,59,60,61,62,63,64};


    double x[N] = {0};

    start = clock();
    solveLU(A, b, x);

    cout << "   Solution LU:" << endl;
    for (int i = 0; i < N; i++)
        cout << " " << x[i] << " ";
    cout << endl;
    stop = clock();
    czas1 = (double)(stop - start) / CLOCKS_PER_SEC;
    cout << " time: " << czas1 << endl << endl;
    
    
    double x1[N] = {0};
    start = clock();
    cholesky(A, b, x1);

    cout << "   Solution cholesky:" << endl;
    for (int i = 0; i < N; i++)
        cout << " " << x1[i] << " ";
    cout << endl;
    stop = clock();
    czas2 = (double)(stop - start) / CLOCKS_PER_SEC;
    cout << " time: " << czas2 << endl << endl;
    

    return 0;
}





