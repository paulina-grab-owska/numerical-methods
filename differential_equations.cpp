#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double function(double x, double y) {
    return (1/x); 
}

void euler(double x0, double y0, double h, int N, double* x_arr, double* y_arr) {
    x_arr[0] = x0;
    y_arr[0] = y0;
    
    for (int i = 1; i <= N; ++i) {
        x_arr[i] = x_arr[i - 1] + h;
        y_arr[i] = y_arr[i - 1] + h * function(x_arr[i - 1], y_arr[i - 1]);
    }
}

void heun(double x0, double y0, double h, int N, double* x_arr, double* y_arr) {
    x_arr[0] = x0;
    y_arr[0] = y0;

    for (int i = 1; i <= N; ++i) {
        double x_prev = x_arr[i - 1];
        double y_prev = y_arr[i - 1];
        double y_euler = y_prev + h * function(x_prev, y_prev); 
        x_arr[i] = x_prev + h;
        y_arr[i] = y_prev + (h / 2) * (function(x_prev, y_prev) + function(x_arr[i], y_euler));
    }
}

void rk4(double x0, double y0, double h, int N, double* x_arr, double* y_arr) {
    x_arr[0] = x0;
    y_arr[0] = y0;

    for (int i = 1; i <= N; ++i) {
        double x_prev = x_arr[i - 1];
        double y_prev = y_arr[i - 1];
        double k1 = h * function(x_prev, y_prev);
        double k2 = h * function(x_prev + h / 2, y_prev + k1 / 2);
        double k3 = h * function(x_prev + h / 2, y_prev + k2 / 2);
        double k4 = h * function(x_prev + h, y_prev + k3);
        x_arr[i] = x_prev + h;
        y_arr[i] = y_prev + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
    }
}


int main() {
    double x0 = 0;
    double y0 = 1;
    double h = 0.5;
    double b = 3;
    int N = static_cast<int>((b - x0) / h);

    double x_arr_euler[N + 1];
    double y_arr_euler[N + 1];
    double x_arr_heun[N + 1];
    double y_arr_heun[N + 1];
    double x_arr_rk4[N + 1];
    double y_arr_rk4[N + 1];

    euler(x0, y0, h, N, x_arr_euler, y_arr_euler);
    heun(x0, y0, h, N, x_arr_heun, y_arr_heun);
    rk4(x0, y0, h, N, x_arr_rk4, y_arr_rk4);

    cout << "\n     Euler:\n";
    cout << "   x\t\t y\n";
    for (int i = 0; i <= N; ++i) {
        cout << "   "<< x_arr_euler[i] << "\t " << y_arr_euler[i] << endl;
    }

    cout << "\n     Heun:\n";
    cout << "   x\t\t y\n";
    for (int i = 0; i <= N; ++i) {
        cout << "   " << x_arr_heun[i] << "\t " << y_arr_heun[i] << endl;
    }

    cout << "\n     RK4:\n";
    cout << "   x\t\t y\n";
    for (int i = 0; i <= N; ++i) {
        cout << "   "<< x_arr_rk4[i] << "\t " << y_arr_rk4[i] << endl;
    }

    return 0;
}

