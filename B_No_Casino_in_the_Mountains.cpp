#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'


void solve()
{
    ll n, k;
    cin >> n>>k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll res=0;
    ll curr=0;
    int i=0;
    for (i = 0; i < n; i++)
    {
        if(a[i]==1){
            curr=0;
        }else{
            curr++;
        }
        if(curr==k){
            res++;
            i++;
            curr=0;
        }
    }
    cout << res << endl;

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