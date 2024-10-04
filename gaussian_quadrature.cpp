#include <iostream>
#include <cmath>
using namespace std;

double gaussQuadArea(double xys[][2], double points[], double w[], int numPoints) {
    double dKSI[2][4];
    double dETA[2][4];
    double function[2][2];
    double dxdKSI, dydKSI, dxdETA, dydETA;
    double area = 0.0;

    // pochodne cząstkowe
    for (int i = 0; i < 2; i++) {
        dKSI[i][0] = -0.25 * (1.0 - points[i]);
        dKSI[i][1] = 0.25 * (1.0 - points[i]);
        dKSI[i][2] = 0.25 * (1.0 + points[i]);
        dKSI[i][3] = -0.25 * (1.0 + points[i]);
  
        dETA[i][0] = -0.25 * (1.0 - points[i]);
        dETA[i][1] = -0.25 * (1.0 + points[i]);
        dETA[i][2] = 0.25 * (1.0 + points[i]);
        dETA[i][3] = 0.25 * (1.0 - points[i]);
    }

    // wyznacznik Jacobianu
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            dxdKSI = dKSI[i][0] * xys [0][0] + dKSI[i][1] * xys[1][0] + dKSI[i][2] * xys[2][0] + dKSI[i][3] * xys [3][0];
            dydKSI = dKSI[i][0] * xys [0][1] + dKSI[i][1] * xys[1][1] + dKSI[i][2] * xys[2][1] + dKSI[i][3] * xys [3][1];
            dxdETA = dETA[j][0] * xys [0][0] + dETA[j][1] * xys[1][0] + dETA[j][2] * xys[2][0] + dETA[j][3] * xys [3][0];
            dydETA = dETA[j][0] * xys [0][1] + dETA[j][1] * xys[1][1] + dETA[j][2] * xys[2][1] + dETA[j][3] * xys [3][1];
  
            function[i][j] = dxdKSI * dydETA - dydKSI * dxdETA;
        }
    }
    
    // powierzchnia czworokąta
    for (int i = 0; i < numPoints; i++) {
        for (int j = 0; j < numPoints; j++) {
            area += abs(function[j][i]) * w[i] * w[j];
        }
    }
  
    return area;
}

int main () {
    double xys [4][2] = {{-1, 0}, {0, 3.8}, {1, 0}, {0, 4}}; 
    double points [2] = {0.577350269, -0.577350269}; 
    double w [2] = {1.0, 1.0}; 
 
    double area = gaussQuadArea (xys, points, w, 2);
    cout << "area of quadrangle: " << area << endl;
  
    return 0;
}




