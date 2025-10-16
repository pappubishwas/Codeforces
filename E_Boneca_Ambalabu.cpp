#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve()
{
    int n, k, m,l,r;
    string p,s;
    cin>>n;
    vector<int>pap(n);
    for(auto &p:pap) cin>>p;
    vector<int> btc(32);
    for(int i=0;i<32;i++){
        int cnt=0;
        for(int j=0;j<n;j++){
            if(pap[j] & 1<<i) cnt++;
        }
        btc[i]=cnt;
    }
    int res=0;
    for(int i=0;i<n;i++){
        int t=0;
        for(int j=0;j<32;j++){
            int one=btc[j];
            if(pap[i] & 1<<j) one=n-one;
            t+=(one*(1<<j));
        }
        res=max(res,t);
    }
    cout<<res<<endl;
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