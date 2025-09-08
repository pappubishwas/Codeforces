#include<bits/stdc++.h>
using namespace std;
using ll = long long;
bool even(ll x) {
    return x % 2 == 0;
}
void solve() {
   ll k,n,a,b,res=-1;
   cin>>a>>b;
   vector<ll> fact;

   if(even(a) && even(b)){
       cout<<a*(b/2)+2<<endl;
       return;
   }else if(even(a) && !even(b)){
       cout<<-1<<endl;
       return;
   }else if(!even(a) && !even(b)){
       cout<<a*b+1<<endl;
       return;
    }else{
       if(even(b/2)){
              cout<<a*(b/2)+2<<endl;
              return;
       }
       cout<<-1<<endl;
    }














//    for(int i=1;i<=sqrt(b);i++){
//        if(b%i==0){
//     ll ta=a*(b/i);
//     ll tb=i;
//     if((ta+tb)%2==0){
//         cout<<ta+tb<<endl;
//         return;
//     }
//     ll t=(a*i+b/i);
//     if(t%2==0) res=max(res,t);
//        }
//    }
//    cout<<res<<endl;
//    return;

//    for(int i=0;i<fact.size();i++){
//     ll ta=a*fact[i];
//     ll tb=b/fact[i];
//     if((ta+tb)%2==0){
//         res=max(res,ta+tb);
//     }
//    }
//    cout<<res<<endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}