#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int INF = 1e18;
ll lcm(ll a,ll b){
    return (a*b)/__gcd(a,b);
}
void solve() {
    ll n,k,tp=0;
    cin>> n;
    vector<ll> a(n);
    set<ll> s;
    for(int i=0;i<n;i++){
        cin>> a[i];
    }
    for(int i=1;i<n;i++){
        ll lcmval=__gcd(a[i],a[i-1]);
        s.insert(a[i-1]/lcmval);
    }
    ll res=1;
    for(auto x:s){
        res=lcm(res,x);
    }
    cout<<res<<"\n";
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
