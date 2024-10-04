#include <iostream>

using namespace std;


void displayMatrix(double matrix[][21], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n + 1; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

void gaussianElimination(double matrix[][21], int n) {
    for (int i = 0; i < n; ++i) {
        double maxEl = abs(matrix[i][i]);
        int maxRow = i;
        for (int k = i + 1; k < n; ++k) {
            if (abs(matrix[k][i]) > maxEl) {
                maxEl = abs(matrix[k][i]);
                maxRow = k;
            }
        }

        for (int k = i; k < n + 1; ++k) {
            double tmp = matrix[maxRow][k];
            matrix[maxRow][k] = matrix[i][k];
            matrix[i][k] = tmp;
        }

        for (int k = i + 1; k < n; ++k) {
            double c = -matrix[k][i] / matrix[i][i];
            for (int j = i; j < n + 1; ++j) {
                if (i == j) {
                    matrix[k][j] = 0;
                } else {
                    matrix[k][j] += c * matrix[i][j];
                }
            }
        }
    }

    // postepowanie odwrotne
    double solution[n];
    for (int i = n - 1; i >= 0; --i) {
        solution[i] = matrix[i][n] / matrix[i][i];
        for (int k = i - 1; k >= 0; --k) {
            matrix[k][n] -= matrix[k][i] * solution[i];
        }
    }

    cout << "\n output:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "x" << i + 1 << " = " << solution[i] << endl;
    }
}

int main() {
    double matrix[20][21] = {{5.10433490e+00, 1.75969137e+00, 3.34269222e+00, 1.69270851e+00,
  2.10571531e+00, 2.88859060e+00, 7.58084997e+00, 7.89813209e+00,
  3.22961138e+00, 2.74727035e+00, 1.64047227e+00, 8.50491285e-01,
  9.92490806e+00, 8.17924897e+00, 5.55289459e+00, 1.42494093e+00, 
  2.76959304e+00, 1.56532834e-01, 6.66525688e+00, 1.67808636e+00, 0.37420695},
                            {2.51787444e+00, 8.85065540e+00, 6.96539888e+00, 7.74759713e+00,
  1.69969840e-01, 9.25868652e+00, 8.47749420e+00, 2.61761845e-01,
  3.94321306e+00, 5.89072001e+00, 8.29337823e+00, 2.20212145e+00,
  7.22467370e-03, 4.30461845e+00, 3.28503270e+00, 8.94091309e+00,
  4.78059184e+00, 8.36653930e+00, 1.44848560e+00, 3.45006255e+00, 3.21757695},
                            {3.74780917e-02, 5.07160375e+00, 3.63896851e+00, 4.77241115e+00,
  4.97797037e+00, 5.43678447e+00, 6.30858043e+00, 5.55483663e+00,
  3.29617157e+00, 2.44656662e+00,8.70682154e+00, 7.59035931e+00,
  3.75598973e+00, 6.20465356e+00, 9.60523352e-01, 4.15748008e-01,
  5.67764815e-01, 2.29292958e+00, 4.43041021e-01,8.20206925e+00, 7.84957695},
                            {1.00599731e+00, 6.22345945e+00, 7.93202559e+00, 7.97800763e+00,
  3.94323078e-01, 5.71393977e+00, 5.80092904e+00, 1.73848000e+00,
  7.03076629e+00, 2.15698396e+00, 6.28935358e+00, 6.76508355e+00,
  5.28644884e+00, 7.80555007e+00 ,5.22660948e+00, 5.42241227e+00,
  6.22280648e+00, 2.29594435e+00, 3.66192245e+00, 8.94837190e+00, 6.72922658},
                            {5.04506405e+00 ,5.80367597e+00 ,8.92849022e+00,7.47350443e+00,
  3.81950675e+00, 9.55397235e+00, 7.86375898e+00, 8.97189930e+00,
  2.04109623e+00, 1.04662443e+00 ,7.18326849e+00, 4.74199460e+00,
  7.47098892e+00, 6.52205664e+00, 5.90895425e+00, 6.80910265e+00,
  6.89623538e+00, 7.82277807e+00 ,3.03142408e+00, 3.93553100e-01, 2.00267396},
                            {4.45523365e+00, 6.01620888e+00, 2.88395450e+00, 6.96428198e+00,
  7.73912909e+00, 2.85965153e+00, 3.60405756e+00 ,6.10323893e+00,
  6.55659667e+00, 6.79311561e+00, 2.92094880e-01 ,5.40647851e+00,
  6.55074767e-01 ,3.23988216e+00 ,3.70867922e+00, 8.76834262e+00,
  6.61527717e+00 ,5.05942327e+00 ,3.81894900e+00 ,6.78664542e+00, 5.23242394},
                            {9.27976892e+00, 3.91287173e-01, 9.40598010e+00, 6.93501657e+00,
  1.25907761e+00, 6.07041081e+00, 3.73698707e+00, 3.32356886e+00,
  8.02306992e+00, 9.09421238e+00 ,9.05273293e+00 ,1.01063740e+00,
  3.34950663e+00, 7.67360842e+00, 1.21020805e+00 ,6.41917805e+00,
  5.82974058e-01 ,8.64370265e+00 ,7.49893468e+00, 7.34494266e+00, 4.27969739},
                            {2.36519035e+00, 2.69722816e+00, 4.01132931e+00, 6.04524995e-01,
  2.78986742e+00, 5.88113190e-01, 1.70759426e+00, 1.88147281e+00,
  4.97805120e+00, 7.15255989e+00, 6.75748205e+00, 8.66745105e+00,
  9.63209183e+00, 8.22806126e+00, 9.77046017e+00, 9.87722962e+00,
  2.27708536e+00, 3.42119156e+00, 8.35105691e+00, 8.55444398e+00, 4.81143087},
                            {6.32598011e+00, 5.56797387e+00, 3.27672707e+00, 4.49173411e+00,
  3.88967740e+00, 3.79663182e-01, 5.55830142e+00, 6.05870363e+00,
  4.26713016e+00, 6.96345639e+00, 7.35682525e+00, 1.57858773e+00,
  1.64768488e+00, 5.11799385e+00, 4.69080581e+00, 9.54082419e+00,
  1.31438264e+00, 7.26865764e+00, 7.52952520e+00, 3.16112249e+00, 2.13077584},
                            {5.96547032e+00, 5.78959748e+00, 3.53345854e+00, 8.37157841e-01,
  4.77173930e+00, 9.19910453e+00, 1.06503884e+00, 2.26380068e+00,
  6.26659347e+00 ,6.87270384e+00, 4.48992683e+00, 4.45212059e+00,
  5.91484727e+00 ,2.87956094e+00, 7.56822762e+00, 5.35478736e+00,
  5.91397316e+00 ,5.94583961e-01, 6.59043999e+00,4.43922465e+00, 1.79740411},
                            {3.63303691e+00, 9.11389066e+00, 4.23603836e+00 ,8.73014942e-01,
  3.65089960e+00, 4.18420322e+00, 3.35587359e+00, 8.28711266e+00,
  7.58771886e+00, 9.94696512e+00, 8.40620542e+00 ,1.25716918e+00,
  4.40411940e+00, 5.83188472e+00, 3.93880154e-01, 4.96834824e+00,
  4.52895273e+00, 5.21410603e+00, 8.60665147e+00,4.54284683e+00, 2.78116646},
                            {2.91323767e+00, 1.44008056e+00, 4.23208327e+00, 3.00957861e-01,
  1.08987750e+00, 5.48323873e+00, 1.96486696e+00, 1.01730182e+00,
  6.35255648e+00, 2.96065467e+00, 9.72233337e+00, 9.70441754e+00,
  3.07306254e+00, 9.53766596e+00, 5.87427411e+00, 5.46489467e+00,
  1.04610751e+00, 1.82749805e+00, 2.88475357e+00, 7.11506000e+00, 9.07648293},
                            {9.96272469e+00, 6.94720317e+00 ,5.76208837e+00, 5.14148927e+00,
  2.42928342e-01, 4.78850571e-01,7.60312581e+00, 4.07857444e+00,
  5.42740508e+00, 9.59580480e+00 ,3.29723088e+00, 3.32570968e+00,
  2.07962047e+00 ,4.36821045e+00, 1.38199237e+00 ,1.21833966e+00,
  3.84247551e+00, 6.13067429e+00 ,4.12853462e+00, 2.31645282e+00, 7.60278802},
                            {1.81356132e+00,6.85345417e-01, 9.34653337e+00, 8.10179528e+00,
  8.14915767e+00, 7.30401328e+00, 4.24759787e+00 ,6.43647092e-02,
  2.89913710e+00, 4.44501423e+00, 4.07712828e+00, 3.01926374e+00,
  3.11920370e+00, 5.86888955e+00,2.47016437e+00, 9.53229639e+00,
  3.44072622e+00 ,2.41160594e+00 ,4.47801568e+00, 1.02601112e+00, 0.44804225},
                            {2.36171217e+00, 3.80714231e+00, 9.04112234e+00, 9.93247987e-01,
  8.01372338e+00, 5.36806789e+00, 6.64952989e+00, 3.21883742e+00,
  5.76103675e+00, 2.28765379e+00, 8.76735948e-01, 2.63635605e+00,
  2.21634567e+00, 8.30723171e+00, 2.47507677e+00, 3.78674492e+00,
  8.32553680e+00, 6.59268067e+00, 7.52608251e+00, 8.38006564e+00, 3.03032564},
                            {4.46482512e+00, 1.13144056e+00, 5.85889396e+00, 8.64117482e+00,
  6.10507694e+00, 4.26822267e+00, 6.75249314e+00, 9.39769297e+00,
  8.62397307e+00, 7.48413287e-02, 9.05092405e+00, 1.34185519e+00,
  6.93917786e+00, 3.36307954e+00, 1.46575447e+00, 8.38722476e+00,
  3.96298772e+00, 7.21608290e-01 ,3.99208685e+00, 5.62599782e+00, 1.08351171},
                            {8.81342133e+00, 4.45953067e+00, 2.31022845e+00, 4.58171052e+00,
  2.41465605e+00, 4.49131090e+00 ,8.04915367e+00, 8.59212755e-01,
  9.99860407e+00, 3.93193991e-02, 3.36702510e+00, 6.13047314e+00,
  2.92667166e+00 ,2.16410499e+00, 8.77746429e+00, 2.77522324e+00,
  8.81347467e+00 ,4.08634046e-01, 7.88836051e+00, 3.50529396e+00, 6.82213138},
                            {4.54377058e+00, 8.57130416e+00, 9.57173070e-01, 1.81131982e-01,
  2.61306214e+00, 1.08561613e+00, 9.88020918e+00, 9.61983697e+00,
  7.98149672e+00, 1.02130046e+00, 8.11118393e+00, 8.99452642e+00,
  3.42575761e+00, 8.93780489e+00, 7.82694356e+00, 6.70572668e+00,
  3.81870093e+00, 9.97967854e+00, 5.14824629e+00, 6.68100978e+00, 6.96424131},
                            {4.09244084e+00, 6.47744012e+00, 4.31626204e-01, 2.01357125e+00,
  9.07116695e+00, 5.00847293e+00, 9.34224113e+00, 7.91980139e+00,
  2.45861412e+00, 8.37514505e+00, 8.19399706e+00, 1.19978850e+00,
  3.10794710e+00, 4.02921482e+00, 5.37454753e+00, 2.27273053e+00,
  1.46724630e+00, 6.26394725e+00, 7.51526370e+00, 6.64156544e+00, 6.5750299 },
                            {9.76335803e+00, 5.02048297e+00, 8.16110497e+00, 3.17586938e+00,
  6.24951419e+00, 1.97398801e+00, 5.05391652e+00, 4.50493279e+00,
  9.73979315e+00, 8.58993726e+00 ,6.24727732e+00 ,6.89333240e+00,
  9.52123357e+00, 2.02189392e-01 ,8.13574765e+00 ,9.03349868e-01,
  9.87113674e+00, 6.77803126e+00, 9.99926084e+00, 6.43465967e+00, 2.76621875}};
    int n = 20;                                  // rozmiar macierzy

    cout << "input matrix:" << endl;
    displayMatrix(matrix, n);

    gaussianElimination(matrix, n);

    return 0;
}



