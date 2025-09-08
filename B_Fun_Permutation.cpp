#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
   ll k,n;
   cin>>n;
   vector<ll> a(n);
   for(int i=0;i<n;i++) cin>>a[i];
   k=n+1;
   for(int i=0;i<n;i++){
       cout<<k-a[i]<<" ";
   }
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