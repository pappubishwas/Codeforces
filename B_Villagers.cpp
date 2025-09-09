#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
   ll k,x,n;
   cin>>n;
   vector<int> v(n);
   for(int i=0;i<n;i++){
       cin>>v[i];
   }
   sort(v.begin(),v.end());
   ll res=0;
   for(int i=n-1;i>=0;i-=2){
       res+=v[i];
   }
   cout<<res<<endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}