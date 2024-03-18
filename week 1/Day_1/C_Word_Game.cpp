#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll t, n, m;
void solve()
{
   map<string, int> mp;
   string a, b, c;
   cin >> n;

   cin.ignore();
   getline(cin, a); // input
   getline(cin, b);
   getline(cin, c);

   string word;
   stringstream aa(a);
   stringstream bb(b);
   stringstream cc(c);

   while (aa >> word)mp[word]++;
   while (bb >> word)mp[word]++;
   while (cc >> word)mp[word]++;

   // for (auto i = mp.begin(); i != mp.end(); i++)
   // cout << i->first << " " << i->second << " ";
   // cout << endl;

   int c1 = 0, c2 = 0, c3 = 0;
   stringstream aaa(a);
   stringstream bbb(b);
   stringstream ccc(c);

   while (aaa >> word)
   {
      if (mp[word] == 1)c1 = c1 + 3;
      if (mp[word] == 2)c1 = c1 + 1;
   }
   while (bbb >> word)
   {
      if (mp[word] == 1)c2 = c2 + 3;
      if (mp[word] == 2)c2 = c2 + 1;
   }
   while (ccc >> word)
   {
      if (mp[word] == 1)c3 = c3 + 3;
      if (mp[word] == 2)c3 = c3 + 1;
   }
   cout << c1 << " " << c2 << " " << c3 << '\n';
}
int main()
{
   ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
   cin >> t;
   while (t--)
      solve();
}
