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
    vector<int> ans;
    ans.push_back(-131);
    for (int i = 0; i < n; i++)
    {
        /* code */
        int k;
        cin >> k;
        ans.push_back(k);
    }
    bool p = true;
    int k = 2;
    for (int i = 3; i < n; i++)
    {
        while (i < n && i < pow(2, k))
        {
            if (ans[i] > ans[i + 1])
            {
                p = false;
                break;
            }
            i++;
        }
        if (!p)
            break;
        k++;    
    }
    if (p)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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