#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
    int t, c = 0, n, k;
    cin >> n >> k;
    vector<int> ans(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> ans[i];
    }
    if (k > 1)
        cout << "YES" << endl;
    else
    {
        for (size_t i = 1; i < n; i++)
        {
            if(ans[i-1]>ans[i]){
                cout<<"NO"<<endl;
                return;
            }
        }
        cout << "YES" << endl;
    }
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