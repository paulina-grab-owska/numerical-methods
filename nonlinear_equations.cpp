#include <iostream>
#include <cmath>

using namespace std;


double function(double x) {
    return (x+sqrt(x*x*x)); 
}

double first_derivative(double x, double h) {
    return ((function(x + h) - function(x)) / h);
}

double bisection_method(double a, double b, double epsilon) {
    double fa = function(a);
    double fb = function(b);
    if (fa * fb > 0) {
        cout << "no root in given interval. " << endl;
        return 0;
    }

    while ((b - a) / 2 > epsilon) {
        double x = (a + b) / 2;
        double fx = function(x);
        if (fx == 0.0)
            return x;
        else if (fa * fx < 0)
            b = x;
        else
            a = x;
    }
    return (a + b) / 2;
}


double Newton_Raphson_method(double xn, double epsilon, double h) {
    double xn_plus_1 = xn - function(xn) / first_derivative(xn, h);

    if (abs(function(xn_plus_1)) <= epsilon)
        return xn_plus_1;
    else
        return Newton_Raphson_method(xn_plus_1, epsilon, h);
}



int main() {
    double a = 0.0;                  // beginning of the interval for bisection_method
    double b = 2.0;                 // ending of the interval for bisection_method
    
    double x0 = 0.5;                // beginning point for N-R
    double h = 0.0001;               // for calculating the derivative
    
    double epsilon = 0.0001;        // accuracy

    cout << "bisection method: " << bisection_method(a, b, epsilon) << endl << endl << endl; 
    cout << "Newton-Raphson method: " << Newton_Raphson_method(x0, epsilon, h) << endl;

    return 0;
}

