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
   sort(v.begin(),v.end());;
   for(int i=n-1;i>0;i--){
       if(v[i]==v[i-1]){
        cout<<"YES"<<endl;
        return;
       }
   }
   cout<<"NO"<<endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}