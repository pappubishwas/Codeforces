#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define INF 1000000000000000000LL;

void solve(){
    ll n,t,m,p,q;
    cin>>n;
    vector<ll> pap(n),ans(n);
    ans[0]=1;
    ll nxt=2;
    for(auto &x:pap) cin>>x;
    for(ll i=1;i<n;i++){
        ll el=pap[i-1]+i+1;
        if(el==pap[i]){
            ans[i]=nxt;
            nxt++;
        }else{
            ans[i]=ans[el-pap[i]-1];
        }
    }
    for(auto &x:ans)cout<<x<<" ";
    cout<<endl;
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