#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll findSum(string &s){
    ll c=0;
    for(auto &d:s)
    c+=(d-'0');
    return c;
}


ll findPairs(vector<string> &v){
    vector<vector<ll>> dp(11,vector<ll>(60,0));
    ll ans = 0;
    ll n=v.size();
    
     for(int i=0;i<n;i++){
        string &s = v[i];
        ll sum = findSum(s);
        ll len = s.size();
         dp[len][sum]++;
     }
    
    
    for(int i=0;i<n;i++){
        string s=v[i];
        ll sum = findSum(v[i]);
        ll len = s.size();
        
        ans+= dp[len][sum];
        
        // considering it as prefix
        ll removedSum = 0, r=0;
        for(ll i=len-1;i>0;i--){
            removedSum+=(s[i] - '0');
            r++;
            
            ll left = len-r;
            ll leftSum = sum - removedSum ;
            
            ll remainingRight = left - r;
            ll remainingRightSum = leftSum - removedSum;
            
            if(remainingRight>=0 && remainingRightSum>=0  && ((left + remainingRight + r)%2==0))
            ans+= dp[remainingRight][remainingRightSum];
        }
        
        // considering it as suffix
        removedSum = 0, r=0;
        for(int i=0;i<len-1;i++){
            removedSum+=(s[i] - '0');
            r++;
            
            ll right = len-r;
            ll rightSum = sum - removedSum;
            
            ll remainingLeft = right - r;
            ll remainingLeftSum = rightSum - removedSum;
            
            if(remainingLeftSum>=0 && remainingLeft >=0 && ((right + remainingLeft + r)%2==0))
            ans+= dp[remainingLeft][remainingLeftSum];
        }

        
    }
    // ans+=n;
    return ans;
}


void solve(){
    ll n;
    cin>>n;
    vector<string> v(n);

    for(int i=0;i<n;i++){
    cin>>v[i];
    }
    
    ll ans = findPairs(v);
    
    
    cout<<ans<<"\n";
    
}

int main(){
    
    ll t=1;
    // cin>>t;
    while(t--)
    solve();
    
    return 0;
}