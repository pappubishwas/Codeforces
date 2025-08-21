#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
        ll n, c,k;
        cin >> n ;
        string s;
        cin>>s;
        vector<int> a(26);
        ll mx=INT_MIN,mn=INT_MAX;
        for(int i=0;i<n;i++){
            a[s[i]-'a']++;
        }
        for(int i=1;i<n-1;i++){
            if(a[s[i]-'a']>1){
                cout<<"Yes"<<endl;
                return;
            }
        }
        cout<<"No"<<endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}


