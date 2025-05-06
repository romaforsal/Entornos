#include <iostream>
using namespace std;
int main()
{
    double a;
    double b;
    double c;
    cout << "Di el valor a";
    cin >> a;
    cout << "Di el valor b";
    cin >> b;
    cout << "Di el valor c";
    cin >> c;
    double X1;
    double X2;
    X1 = (-b) + sqrt((b * b) - (4 * a * c) / (2 * a));
    cout << "X1 = " << X1;
    X2 = (-b) - sqrt((b * b) - (4 * a * c) / (2 * a));
    cout << "X2 = " << X2;