#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll t, n, m;
void solve()
{
   string a;
   cin >> a;
   int c[26] = {0}, flg = 0;
   char x;
   for (int i = 0; i < a.size(); i++)
      c[a[i] - 97]++;

   for (int i = 0; i < 26; i++)
      if (c[i] == 0)
      {
         x = char(i + 97);
         flg = 1;
         break;
      }

   if (flg)
      cout << x << '\n';
   else
      cout << "None\n";
}
int main()
{
   ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
   solve();
}
