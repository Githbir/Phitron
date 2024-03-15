#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll t, n, m;
void solve()
{
   cin >> n >> m;
   if (n > m)
      cout << 0;
   else
      cout << (m - n) + 1;
   cout << '\n';
}
int main()
{
   ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

   solve();
}
