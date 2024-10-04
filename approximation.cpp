#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;


void least_squares(double x[], double y[], int n, double &a, double &b, double &r) {
    double sum_x = 0, sum_y = 0, sum_xy = 0, sum_x_squared = 0, sum_y_squared = 0;

    for (int i = 0; i < n; ++i) {
        sum_x += x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
        sum_x_squared += x[i] * x[i];
        sum_y_squared += y[i] * y[i];
    }

    a = (n * sum_xy - sum_x * sum_y) / (n * sum_x_squared - sum_x * sum_x);

    b = (sum_y * sum_x_squared - sum_x * sum_xy) / (n * sum_x_squared - sum_x * sum_x);
    
    r = ((n * sum_xy) - (sum_x * sum_y)) / (sqrt(n * sum_x_squared - (sum_x * sum_x)) * sqrt(n * sum_y_squared - (sum_y * sum_y)));
}



int main() {
    
    ifstream file("data.txt");

    if (!file.is_open()) {
        cout << "no such file exits" << endl;
        return 1;
    }

    
    int n;
    file >> n;

    double x[n];
    double y[n];
  

    for (int i = 0; i < n; ++i) {
        file >> x[i] >> y[i];
    }
 
 
    double a, b, r;
    
    least_squares(x, y, n, a, b, r);

    cout << "coefficient a: " << a << endl;
    cout << "coefficient b: " << b << endl;
    
    cout << "correlation coefficient r: " << r << endl;
    
    
    file.close();

    return 0;
}
