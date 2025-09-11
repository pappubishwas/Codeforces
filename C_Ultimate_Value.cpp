#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int INF = 1e18;

void solve() {
    ll n;
    cin>> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        /* code */
        cin>> a[i];
    }
    ll res=0;
    ll mx = -1e18, mn = 1e18,mxswap=0;
    for(int i=0;i<n;i++){
        if(i%2==1){
            res-=a[i];
            mx=max(mx,2*a[i]-i);
            mxswap=max(mxswap,(2*a[i]+i)-mn);
        }else{
            res+=a[i];
            mn=min(mn,2*a[i]+i);
            mxswap=max(mxswap,mx-(2*a[i]-i));
        }
    }
    
    if(n%2==0)
        cout<<res+max(n-2,mxswap)<<"\n";
    else
        cout<<res+ max(n-1,mxswap)<<"\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
