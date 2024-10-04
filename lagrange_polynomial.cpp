#include <iostream>
#include <fstream>

using namespace std;

double lagrange_interpolation(double x[], double y[], int n, double input_data) {
    
    double L = 0.0;

    for (int i = 0; i < n; ++i) {
        double l = y[i];
        for (int j = 0; j < n; ++j) {
            if (j != i) {
                l *= (input_data - x[j]) / (x[i] - x[j]);
            }
        }
        L += l;
    }

    return L;
}

int main() {
/*    
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
    
*/    
    

    int n = 1000;
    double x[n];
    double y[n];
    
    for (int i = 0; i < n; ++i) {
        x[i] = i;
        y[i] = i * i;
    }

    
    double input_data;
    cout << "input data x for intepolation: ";
    cin >> input_data;

    double interpolatedValue = lagrange_interpolation(x, y, n, input_data);

    cout << "interpolated data in point " << input_data << ": " << interpolatedValue << endl;

//    file.close(); //

    return 0;
}



