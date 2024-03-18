#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll t, n, m;
void solve()
{
   cin >> n;
   if (n < 10)
      cout << "000" << n;
   else if (n < 100)
      cout << "00" << n;
   else if (n < 1000)
      cout << "0" << n;
   else
      cout << n;
   cout << '\n';
}
int main()
{
   ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

   solve();
}
