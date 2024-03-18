#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll t, n, m;
void solve()
{
   ll sum = 0, mx = 0;
   cin >> n;
   ll a[n];
   for (int i = 0; i < n; i++)
      cin >> a[i];
   sort(a, a + n, greater<ll>());
   ll mn = 1e18;
   for (int i = 0; i < n; i++)
   {
      sum = sum + a[i];
      if (a[i] % 2 == 1)
         mn = min(mn, a[i]);
   }
   if (sum % 2 == 1)
      cout << sum - a[n - 1];
   else
      cout << sum;
   cout << '\n';
}
int main()
{
   ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
   solve();
}