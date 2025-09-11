#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int INF = 1e18;

void solve() {
    ll n,k,tp=0;
    cin>> n;
    vector<ll> a(n);
    set<ll> s;
    for(int i=0;i<n;i++){
        cin>> a[i];
        if(a[i]!=-1)
            s.insert(a[i]);
        
    }
    if(s.size()>1 || s.count(0)){
        cout<<"NO"<<"\n";
        
    }else{
        cout<<"YES"<<"\n";
    }
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
