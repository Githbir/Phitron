#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll t, n, m, c;
void solve()
{
   cin >> n >> m >> c;
   int x = -1;
   for (int i = 1; i <= 1000; i++)
   {
      c = c * i;
      if (c >= n && c <= m)
      {
         x = c;
         break;
      }
   }
   cout << x << '\n';
}
int main()
{
   ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

   solve();
}
