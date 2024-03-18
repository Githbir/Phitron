#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll t, n, m;
void solve()
{
   ll mx = -1;
   cin >> n;
   ll a[n];
   for (int i = 1; i <= n; i++)
   {
      cin >> a[i];
      mx = max(mx, a[i] - i);
   }
   cout << mx << '\n';
}
int main()
{
   ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
   cin >> t;
   while (t--)
      solve();
}
