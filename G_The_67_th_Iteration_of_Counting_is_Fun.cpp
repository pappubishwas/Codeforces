#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
int MOD=676767677;

void Solve() 
{
    int n,m;
    cin>> n >> m;
    vector<int> pap(n);
    for(int i = 0; i < n; i++) cin >> pap[i];
    map<int,int> cnt,frq;
    for(int i = 0; i < n; i++) cnt[pap[i]]++;
    for(int i=0;i<m;i++){
        frq[i+1]+= cnt[i]+frq[i];
    }
    int ans=1;
    for(int i=0;i<n;i++){
        int mn=INT_MAX;
        if(pap[i]==0) continue;
        if(i-1>=0) mn=min(mn,pap[i-1]);
        if(i+1<n) mn=min(mn,pap[i+1]);
        if(mn>=pap[i]){
            ans=0;
            break;
        }
        if(mn==pap[i]-1){
            ans=(ans*frq[pap[i]])%MOD; // current is 2 then mn is 1, before 2 how many are sat
        }else{
            ans=(ans*cnt[pap[i]-1])%MOD; // current is 3 then mn is 1, then at 2, how many sat 
        }
    }
    cout << ans << "\n";
}

int32_t main() 
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);
    
    cin >> t;
    for(int i = 1; i <= t; i++) 
    {
        //cout << "Case #" << i << ": ";
        Solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    //cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}