#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;


double f(double x) {
    return (1/x) ; 
}


double optimization(double a, double b, double tol) {
    const double phi = (1/((1 + sqrt(5.0)) / 2.0)); 

    double x1 = b - phi * (b - a);
    double x2 = a + phi * (b - a);
    double f1 = f(x1);
    double f2 = f(x2);

    while (abs(b - a) > tol) {
        if (f1 < f2) {
            b = x2;
            x2 = x1;
            f2 = f1;
            x1 = b - phi * (b - a);
            f1 = f(x1);
        } else {
            a = x1;
            x1 = x2;
            f1 = f2;
            x2 = a + phi * (b - a);
            f2 = f(x2);
        }
    }

    return (a + b) / 2.0; 
}

int main() {
    double a = -4.0;
    double b = 0.0;
    double tol = 1e-6; 

    
    double min_x = optimization(a, b, tol);
    double min_y = f(min_x);

    cout << "\n\n\tminimum of the function on the interval [" << a << ", " << b << "] \n\tis in point: (" << min_x << "; " << min_y << ")" << endl;


    return 0;
}



/*
funkcje do testów:
--> test 1:    (pow(x-2,2)+2)           DZIAŁA
            przedział:
                double a = 1.0;
                double b = 4.0;
            minimum w pkt 2; 2

--> test 2:  (pow(x,5) + 5 * pow(x,3) - 3 * pow(x,2) -15 * x + 3)           DZIAŁA
            przedział: 
                double a = 0.0;
                double b = 2.0;
            minimum w pkt: 1.0222174; -9.01119219
            
--> test 3: 1/x                         DZIAŁA
            przedział: 
                double a = -4.0;
                double b = -0.5;
            minimum w pkt: -0.5, -2
            
--> test 4: 1/x                 BŁĄD  (ZGODNIE Z OCZEKIWANIAMI)
            przedział: 
                double a = -4.0;
                double b = 0.0;
            minimum w pkt: xxxxxxxxxxxx
            wolfram zwraca komunikat: no global minima found

*/



