#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define INF 1000000000000000000LL;

void solve(){
    ll n,t;
    cin>>n;
    set<ll>pap;
    for(int i=0;i<n;i++) {
        cin>>t;
        pap.insert(t);
    }
    ll ans=1;
    cout<< pap.size()<<endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}