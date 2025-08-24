#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
        ll n, c,k,m;
        cin >> n ;
        string a,b,sq;
        cin>>a;
        cin>>m;
        cin>>b;
        cin>>sq;
        for(int i=0;i<m;i++){
            if(sq[i]=='D'){
                a=a+b[i];
            }else{
                a=b[i]+a;
            }
        }
        cout<<a<<endl;

}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}


