#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
   ll k,n,res=0;
   cin>>n;
   vector<ll> b(n);
   map<ll,ll>mp;
   unordered_map<ll,vector<ll>>mpp;
   for (int i = 0; i < n; i++)
   {
    cin>>b[i];
    mp[b[i]]++;
    mpp[b[i]].push_back(i);
   }
   for(auto a:mp){
    if((a.second%a.first!=0)){
        cout<<-1<<endl;
        return;
    }
    res+=a.second;
   }
   if(res!=n){
    cout<<-1<<endl;
    return;
   }
   ll el=1;
   vector<ll>ans(n);
   for(auto x:mpp){
    ll number_times=mp[x.first]/x.first;
    for(int i=0;i<x.second.size();i++){
        ans[x.second[i]]=el;
        if((i+1)%x.first==0) el++;
    }
   }
   for(auto x:ans) cout<<x<<" ";
   cout<<endl;
   
   
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}