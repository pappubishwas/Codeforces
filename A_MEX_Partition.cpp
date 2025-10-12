#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define INF 1000000000000000000LL;

void solve(){
    ll n,t,m,p,q;
    cin>>n;
    set<ll> s;
    for(ll i=0;i<n;i++){
        cin>>p;
        s.insert(p);
    }
    ll res=0;
    for(auto &t:s){
        if(t==res) res++;
        else break;
    }
    cout<<res<<endl;
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