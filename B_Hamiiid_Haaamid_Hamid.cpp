#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int INF = 1e18;

void solve() {
    ll n,k;
    cin>> n>>k;
    string s;
    cin>> s;
    if(k==n || k==1){
        cout<<1<<endl;
        return;
    }
    ll left=0,right=0;
    k--;
    int i=k;
    while(i>=0){
        if(s[i]=='#'){
            left=i+1;
            break;
        }
        i--;
    }
    i=k;
    while(i<n){
        if(s[i]=='#'){
            right=n-i;
            break;
        }
        i++;
    }
    if(right==0 && left==0){
        cout<<1<<endl;
        return;
    }
    if(left<right){
        left=k;
    }else{
        right=n-k-1;
    }
    cout<<min(left,right)+1<<endl;

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
