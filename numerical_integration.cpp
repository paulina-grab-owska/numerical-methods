#include <iostream>
#include <cmath>
#include <random>

using namespace std;

#define DD double


DD function(DD x) {
    return (x-3);
}


DD rectangle(DD a, DD b, int n) {
    DD dx = (b - a) / n;
    DD result = 0.0;

    for (int i = 0; i < n; ++i) {
        DD xi = a + i * dx + dx;
        result += function(xi);
    }

    return abs(dx * result) ;
}


DD trapeze(DD a, DD b, int n) {
    DD dx = (b - a) / n;
    DD result = (function(a) + function(b)) / 2.0;

    for (int i = 1; i < n; ++i) {
        result += function(a + i * dx);
    }

    return abs(dx * result);
}


DD simpson(DD a, DD b, int n) {
    DD dx = (b - a) / n;
    DD result = function(a) + function(b);

    for (int i = 1; i < n; i += 2) {
        DD x = a + i * dx;
        result += 4 * function(x);
    }
    
    for (int i = 2; i < n - 1; i += 2) {
        DD x = a + i * dx;
        result += 2 * function(x);
    }

    return abs(result * dx / 3.0);
}


DD monte_carlo(DD a, DD b, int n) {
    srand(time(NULL)); 
    
    DD result = 0.0;
    
    for (int i = 0; i < n; ++i) {
        DD xr = a + (b - a) * rand() / RAND_MAX;
        cout << xr << " ; ";
        result += function(xr);
    }
    
    return abs((b - a) * result / n);
}


int main() {
    DD a, b;
    int n;

    cout << "Podaj początek przedziału całkowania (a): ";
    cin >> a;
    cout << "Podaj koniec przedziału całkowania (b): ";
    cin >> b;
    cout << "Podaj liczbę podprzedziałów (n): ";
    cin >> n;

    DD rectangle_check = rectangle(a, b, n);
    DD trapeze_check = trapeze(a, b, n);
    DD simpson_check = simpson(a, b, n);
    DD montecarlo_check = monte_carlo(a, b, n);

    cout << endl << endl << endl;
    cout << "rectangle result: " << rectangle_check << endl << endl;
    cout << "trapeze result: " << trapeze_check << endl <<endl;
    cout << "simpson reslut: " << simpson_check << endl <<endl;
    cout << "monte carlo result: " << montecarlo_check << endl <<endl;

    return 0;
}




