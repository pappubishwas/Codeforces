#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define INF 1000000000000000000LL;

ll que(vector<ll>& v){
    cout<<"? "<<v.size()<<" ";
    for(auto &t:v) cout<<t+1<<" ";
    cout<<endl;
    ll ans;
    cin>> ans;
    return ans;
}

void solve(){
    ll n,t,m,p,q;
    cin>>n;
    vector<ll> ans(2*n),query(1,0);
    for(ll i=1;i<2*n;i++){
        query.push_back(i);
        ll q=que(query);
        if(q){
            ans[i]=q;
            query.pop_back();
        }
    }
    query.clear();
    query.push_back(2*n-1);
    for(ll i=2*n-2;i>=0;i--){
        query.push_back(i);
        if(ans[i]) continue;
        ll q=que(query);
        ans[i]=q;
        query.pop_back();
    }
    cout<<"! ";
    for(auto t:ans) cout<<t<<" ";
    cout<<endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}