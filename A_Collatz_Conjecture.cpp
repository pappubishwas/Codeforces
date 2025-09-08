#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
   ll k,x;
   cin>>k>>x;
   for(int i=1;i<=k;i++){
       x=x*2;
   }
   cout<<x<<endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}