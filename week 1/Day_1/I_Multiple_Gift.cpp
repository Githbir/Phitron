#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll t, n, m, c;
void solve()
{
   cin >> n >> m;
   while (1)
   {
      if (n > m)
         break;
      c++;
      n = n * 2;
   }
   cout << c << endl;
}
int main()
{
   ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
   solve();
}
