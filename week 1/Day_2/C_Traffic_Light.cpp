#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll t, n, m;
void solve()
{
   string s;
   char c;
   cin >> n >> c >> s;
   if (c == 'g')
   {
      cout << 0 << "\n";
      return;
   }
   s = s + s; // s*2
   int l = -1;
   int r = 0;
   for (int i = 0; i < n * 2; i++)
   {
      if (s[i] == c)
      {
         if (l == -1)
            l = i;
      }
      else if (s[i] == 'g')
         if (l != -1)
         {
            r = max(r, i - l);
            l = -1;
         }
   }
   cout << r << "\n";
}
int main()
{
   ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
   cin >> t;
   while (t--)
      solve();
}
