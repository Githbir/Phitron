#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll t, n, m;
void solve()
{
   cin >> n >> m;
   ll a[n], b[m];
   for (int i = 0; i < n; i++)
      cin >> a[i];
   for (int i = 0; i < m; i++)
      cin >> b[i];
   int l = 0, r = 0, ans = 0;
   while (r < m)
   {
      while (b[r] > a[l])
         ans++, l++;
      r++;
      cout << ans << " ";
   }
}
int main()
{
   ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
   solve();
}
