#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
    int res = 0, ind = 1, k, n, minval = INT_MAX;
    cin >> n >> k;
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ans[i];
        int rem = ans[i] % k;
        if (rem == 0)
            minval = min(minval, rem);
        else
            minval = min(minval, k - rem);
    }
    if (k == 4)
    {
        int tw = 0, th = 0;
        for (int i = 0; i < n; i++)
        {
            if (ans[i] % 2 == 0)
                tw++;
            if (ans[i] % 4 == 0)
                tw++;
            if (ans[i] % 4 == 3)
                th++;
            if (tw >= 2)
                minval = 0;
            else if(tw or th)   minval=1;
            else minval=2;  
        }
    }
    cout << minval << endl;
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