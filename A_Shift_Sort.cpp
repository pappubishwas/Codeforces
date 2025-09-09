#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
   ll k,x,n;
   cin>>n;
   vector<int> v(n);
   string s;
   cin>>s;
   ll totalOne=0;
   ll l=0,r=n-1;
   while(l<r){
    if(s[r]=='1'){
        r--;
    }else{
        while (l<r && s[l]=='0'){
            l++;
        }
        if(l<r){
            totalOne++;
            l++;
            r--;
        }
        
    }
   }
   cout<<totalOne<<endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}