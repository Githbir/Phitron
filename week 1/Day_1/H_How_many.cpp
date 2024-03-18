#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll t, n, m, c = 0;
void solve()
{
   cin >> n >> m;
   for (int i = 0; i <= n; i++)
      for (int j = 0; j <= n; j++)
         for (int k = 0; k <= n; k++)
            if (i + j + k <= n && i * j * k <= m)
               c++;

   cout << c << endl;
}
int main()
{
   ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
   solve();
}
