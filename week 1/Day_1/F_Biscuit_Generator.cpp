#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll t, n, m, c;
void solve()
{
   cin >> n >> m >> c;
   int x = 0, tmp = n;
   for (int i = 1; i <= 20; i++)
   {
      if (n > (c + .5))
         break;
      x++;
      n = n + tmp;
   }
   cout << m * x << '\n';
}
int main()
{
   ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
   solve();
}
