#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    int t;
    cin >> t;
    while(t--) {
       ll n,s;
       cin>>n>>s;
       ll res=0;
       for(int i = 0; i < n;i++) {
            ll dx,dy,x,y;
            cin >>dx>>dy>>x>>y;
            if(x==y && dx==dy) res++;
            else if(x+y==s && dx!=dy) res++;
       }
       cout << res << "\n";
    }
    return 0;
}