#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define INF 1000000000000000000LL;

void solve(){
    ll n,t,m,p,q;
    cin>>n>>m>>p>>q;
    if(n%p || m==(n/p)*q) cout<<"YES"<<endl;
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