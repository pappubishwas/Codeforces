#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define INF 1000000000000000000LL;

void solve(){
    ll n,t,m,p,q;
    cin>>n;
    vector<ll> binary;
        if (n == 0) {
        cout << "YES" << endl;
        return; 
    }
    while(n>0){
        if(n%2) binary.push_back(1);
        else binary.push_back(0);
        n/=2;
    }
    while(binary.size()>0 && *binary.begin()==0){
        binary.erase(binary.begin());
    }
    ll l=0,r=binary.size()-1;
    bool flag=true;
    while(l<=r){
        if((l==r && binary[r]==1 ) || (binary[l]!=binary[r])){
            flag=false;
            break;
        }
        l++;
        r--;
    }
    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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