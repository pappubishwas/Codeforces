#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define INF 1000000000000000000LL;

void solve(){
    ll n,t;
    cin>>n;
    vector<ll> pap(n);
    for(ll i=0;i<n;i++){
        cin>>pap[i];
        pap[i]=abs(pap[i]);
    }
    ll md=pap[0];
    sort(pap.begin(),pap.end());
    ll mid=n/2+n%2;
    ll leftElement=pap.end() - find(pap.begin(),pap.end(),md);
    if(leftElement>=mid) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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