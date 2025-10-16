#include<bits/stdc++.h>
using namespace std;
using ll=long long;

void findAns(int r,int c,int n,int val,vector<vector<ll>>& ans){
    if(val<0) return;
    ans[r][c]=val--;
    while(c+1<n && ans[r][c+1]==-1) ans[r][++c]=val--;
    while(r+1<n && ans[r+1][c]==-1) ans[++r][c]=val--;
    while(c-1>=0 && ans[r][c-1]==-1) ans[r][--c]=val--;
    while(r-1>=0 && ans[r-1][c]==-1) ans[--r][c]=val--;
    findAns(r,c+1,n,val,ans);
}

void solve(){
    ll n,t,m,p,q;
    cin>>n;
    vector<vector<ll>> ans(n,vector<ll>(n,-1));
    findAns(0,0,n,n*n-1,ans);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cout<<ans[i][j]<<" ";
        cout<<endl;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}