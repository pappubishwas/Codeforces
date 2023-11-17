#include <bits/stdc++.h>
#include <cstring>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
    int n;
    cin >> n;
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ans[i];
    }
    int k = ans[0] + ans[1];
    string s = "YES";
    for (int i = 1; i < n; i++)
    {
        if (k != (ans[i] + ans[i - 1]))
        {
            s = "NO";
            break;
        }
    }
    cout<<s<<endl;
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