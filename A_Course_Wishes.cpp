#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve() 
{
    int n,k,x;
    cin>> n>>k;
    vector<pair<int,int>> pap(n);
    for(int i=1;i<=k;i++) cin>> x;
    for(int i=0;i<n;i++){
        cin>> pap[i].first;
        pap[i].second=i;
    }
    sort(pap.rbegin(),pap.rend());
    vector<int> ans;
    for(int i=0;i<n;i++){
        for(int j=pap[i].first;j<=k;j++) ans.push_back(pap[i].second+1);
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    cout<<endl;
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