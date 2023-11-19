#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
    int res = 0, ind = 1, k = 0;
    string s;
    cin >> s;
    vector<int> ans;
    while (k < 4)
    {
        if (s[k] == '0')
            ans.push_back(10);
        else
        {
            ans.push_back(s[k] - '0');
        }
        k++;
    }
    for (int i = 0; i < 4; i++)
    {
        res += abs(ans[i] - ind);
        ind = ans[i];
    }
    cout << res + 4 << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}