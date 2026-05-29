#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve() 
{
    int t,h,u;
    cin>> t>>h>>u;
    int ans=0;
    // t and u togather
    int mn=min(t,u);
    ans+=(mn*4);
    t-=mn;
    u-=mn;
    // 2 t and h togather
    mn=min(t/2,h);
    ans+=(mn*7);
    t-=mn*2;
    h-=mn;
    // t and h togather
    mn=min(t,h);
    ans+=(mn*5);
    t-=mn;
    h-=mn;
    // t and t togatther
    if(t>0)
        ans+=(t*2+1);
    ans+=(h*3);
    ans+=(u*3);
    cout<<ans<<endl;
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