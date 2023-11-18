#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
    ll n, res = 0,minel=INT_MAX,ind=-1;
    cin >> n;
    vector<ll> ans(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> ans[i];
        if(minel>ans[i]){
            minel=ans[i];
            ind=i;
        }
    }
    for (ll i = ind+1; i < n; i++)
    {
        if(ans[i]<ans[i-1]){
            ind=-1;
            break;
        }
    }

    cout << ind << endl;
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