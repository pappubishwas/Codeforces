#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve()
{
    int n, k, m,l,r;
    cin>> n>>k;
    vector<int> pap(n),missing;
    map<int,int>mp;
    for(auto &p:pap){
        cin>> p;
        mp[p]++;
    } 

    for(int i=1;i<=n;i++){
        if(mp.find(i)==mp.end()) missing.push_back(i);
    }
    for(int i=0;i<n;i++){
        if(pap[i]!=pap[n-1] && mp[pap[i]]>0){
            missing.push_back(pap[i]);
            mp[pap[i]]=0;
        }
    }
    missing.push_back(pap[n-1]);
    int t=missing.size();
    int s=0;
    while(k>0){
        cout<<missing[s]<<" ";
        k--;
        s++;
        if(s==t) s=0;
    }
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
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case #" << i << ": ";
        Solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}