#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define INF 1000000000000000000LL;

void solve(){
    ll n,t;
    cin>>n;
    string s;
    cin>> s;
    char ch='0';
    ll ans=0;
    for(int i=0;i<n;i++){
        if(s[i]!=ch){
            ans++;
            ch=s[i];
        }
    }
    if(ans==2) cout<<n+1<<endl;
    else if(ans==1 || ans==0) cout<<n+ans<<endl;
    else cout<<n+ans-2<<endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}