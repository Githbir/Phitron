#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll t, n, m, c;
void solve()
{
   cin >> n >> m >> c;

   for (int i = 0; i <= c; i++)
      for (int j = 0; j <= c; j++)
         if (i * n + j * m == c)
         {
            cout << "Yes\n";
            return;
         }
   cout << "No" << '\n';
}
int main()
{
   ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
   solve();
}
