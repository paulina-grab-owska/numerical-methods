#include <iostream>
#include <fstream>
using namespace std;

// ilorazy różnicowe
double difference_quotient(double x[], double y[], int n, int k) {
    if (k == 0) {
        return y[0];
    }
    
    double result = 0.0;
    for (int i = 0; i <= k; ++i) {
        double numerator = 1.0;
        for (int j = 0; j <= k; ++j) {
            if (j != i) {
                numerator *= (x[i] - x[j]);
            }
        }
        result += y[i] / numerator;
    }
    return result;
}

// wartość wielomianu interpolacyjnego w punkcie x


double newton_interpolation(double x[], double y[], int n, double input_data) {
    double result = 0.0;
    double term = 1.0;

    for (int i = 0; i < n; ++i) {
        result += difference_quotient(x, y, n, i) * term;
        term *= (input_data - x[i]);
    }

    return result;
}

int main() {
    
 /*   ifstream file("data.txt");

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

    double interpolatedValue = newton_interpolation(x, y, n, input_data);

    cout << "interpolated data in point " << input_data << "  : " << interpolatedValue << endl;
    
//    file.close();

    return 0;
}






