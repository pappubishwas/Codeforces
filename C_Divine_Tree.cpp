#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    int t;
    cin >> t;
    while(t--) {
       ll n,s,m;
       cin>>n>>m;
       ll res=0;
       if(m<n || m>(ll)n*(n+1)/2) {
           cout << -1 << "\n";
           continue;
       }
       ll rem=n*(n+1)/2-m;
       vector<ll> val(n);
       for(int i=0;i<n;i++) val[i]=i+1;
       for(int i = n-1; i >=0;i--) {
            if(rem<=val[i]-1){
                val[i]-=rem;
                rem=0;
            }else{
                rem-=val[i]-1;
                val[i]=1;
            }
       }
       ll root=*max_element(val.begin(),val.end());
       cout<<root<<"\n";
         for(int i = 0; i < n;i++) {
                if(i+1==val[i]){
                    if(root==i+1) continue;
                    cout<<i+1<<" "<<root<<"\n";
                }else{
                    cout<<i+1<<" "<<val[i]<<"\n";
                }
         }
    }
    return 0;
}