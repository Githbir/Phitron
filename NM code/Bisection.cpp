#include <bits/stdc++.h>
using namespace std;
int main()
{
    double a, b, c, x, y = 1;
    cin >> a >> b >> x;          // here, x = decimal places number
    for (int i = 1; i <= x; i++) // input 0 1 3
        y *= 10;
    if (a < b)
        swap(a, b);
    int i = 1, t = 2;
    cout << fixed << setprecision(4);
    while (t)
    {
        c = (a + b) / 2.0;                         // c = mid point
        double f_of_c = pow(c, 3) + pow(c, 2) - 1; // Given funtion

        cout << i++ << "  a= " << a << "  b= " << b;
        cout << "  c= " << c << "  f(c)= " << f_of_c;
        if (f_of_c > 0)
            a = c, cout << "  Sign_of_f(c)= c>0\n";
        else
            b = c, cout << "  Sign_of_f(c)= c<0\n";
        int d = (abs(a - b)) * y;
        if (int(d) == 0)
            t--;
    }
    cout << "The required root of the given equation up to ";
    cout << int(x) << " decimal places is : " << setprecision(x) << c;
}
