#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve() 
{
    int n, k; cin >> n >>k;
    vector<int> sm(n),left(n),right(n);
    for(auto &t:left) cin>>t;
    for(auto &t:right) cin>>t;
    int result=0;
    for(int i=0;i<n;i++){
        sm[i]=min(left[i],right[i]);
        result+=max(left[i],right[i]);
    }
    sort(sm.begin(),sm.end());
    while(k>1){
        result+=sm[n-1];
        n--;
        k--;
    }
    cout<<result+1<<endl;
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