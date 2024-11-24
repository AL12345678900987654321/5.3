#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double y(double x) {
    if (abs(x) >= 1) {
        return exp(x) / (1 + exp(x) + sin(x));
    }
    else {
        double sum = 0.0;
        double term = 1.0;
        int n = 0;

        while (abs(term) > 1e-6) {
            sum += term;
            n++;
            term *= (-1) * pow(x, 2) / (2.0 * n * (2.0 * n - 1));
        }
        return sum;
    }
}

double f(double x) {
    return y(x / 2) + pow(y(x + 1), 2) + y(2 * x);
}

int main() {
    double fmin, fmax;
    int n;

    cout << "¬вед≥ть початок ≥нтервалу fmin: ";
    cin >> fmin;
    cout << "¬вед≥ть к≥нець ≥нтервалу fmax: ";
    cin >> fmax;
    cout << "¬вед≥ть к≥льк≥сть розбитт≥в n: ";
    cin >> n;

    if (n <= 0) {
        cerr << " ≥льк≥сть розбитт≥в маЇ бути б≥льшою за 0!" << endl;
        return 1;
    }

    double step = (fmax - fmin) / n;

    cout << fixed << setprecision(6);
    cout << "---------------------------------" << endl;
    cout << "|    x    |       f(x)          |" << endl;
    cout << "---------------------------------" << endl;

    for (int i = 0; i <= n; ++i) {
        double x = fmin + i * step;
        double fx = f(x);

        cout << "| " << setw(7) << x << " | " << setw(17) << fx << " |" << endl;
    }

    cout << "---------------------------------" << endl;

    return 0;
}
