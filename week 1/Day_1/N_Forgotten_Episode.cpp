#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll t, n, m;
void solve()
{
   cin >> n;
   ll a[n];
   ll sum = n;
   for (int i = 0; i < n - 1; i++)
      cin >> a[i];

   sort(a, a + n - 1);
   for (int i = 0; i < n - 1; i++)
      if (a[i] != i + 1)
      {
         sum = i + 1;
         break;
      }
   cout << sum << '\n';
}
int main()
{
   ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
   solve();
}
