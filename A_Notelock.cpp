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
    string s;
    l=0;
    cin>> s;
    int cnt=(s[0]=='1') ? 1 : 0;
    int res=cnt;
    for(int i=1;i<n;i++){
        if(s[i]=='1'){
            if(cnt==0) res++;
        }
        if(s[i]=='1') cnt++;
        if(i-l==k-1){
            if(s[l]=='1') cnt--;
            l++;
        }
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