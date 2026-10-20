#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Обчислення суми ряду Тейлора
double S(const double x, const double eps, int& n);

// Обчислення наступного доданка
double A(const double x, const int n, double a);

int main()
{
    double xp, xk, dx, eps;

    cout << "xp = ";
    cin >> xp;

    cout << "xk = ";
    cin >> xk;

    cout << "dx = ";
    cin >> dx;

    cout << "eps = ";
    cin >> eps;

    // Перевірка вхідних даних
    if (xp <= 1 || xk < xp || dx <= 0 || eps <= 0)
    {
        cout << "Error: xp must be > 1, "
            << "xk must be >= xp, dx and eps must be > 0."
            << endl;
        return 1;
    }
    //шапка таблиці
    cout << fixed;
    cout << "--------------------------------------------------------"
        << endl;
    cout << "|" << setw(9) << "x"
        << " |" << setw(15) << "Function"
        << " |" << setw(15) << "Sum"
        << " |" << setw(8) << "Terms" << " |" << endl;
    cout << "--------------------------------------------------------"
        << endl;

    for (double x = xp; x <= xk + dx; x += dx) //я бачу, що в прикладі while
    {
        int n = 0;

        double sum = S(x, eps, n);
        double function = log((x + 1) / (x - 1));

        cout << "|" << setw(9) << setprecision(4) << x
            << " |" << setw(15) << setprecision(8) << function
            << " |" << setw(15) << setprecision(8) << sum
            << " |" << setw(8) << n << " |" << endl;
    }

    cout << "--------------------------------------------------------"
        << endl;

    return 0;
}

// Обчислення суми ряду
double S(const double x, const double eps, int& n)
{
    double a = 2.0 / x;
    double sum = 0.0;

    n = 0;

    while (abs(a) >= eps) //перевірка точності
    {
        sum += a;
        n++;
        a = A(x, n, a);
    }

    return sum;
}

// Рекурентне обчислення наступного доданка
double A(const double x, const int n, double a)
{
    double R = (2.0 * n - 1) /
        ((2.0 * n + 1) * x * x);

    return a * R;
}
