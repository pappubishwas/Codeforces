#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve() 
{
    int n;
    cin>> n;
    int ans;
    for(int i=2*n-1;i>=3;i-=2){
        cout<<"? "<<i<<" "<<i+1<<endl;
        cin>> ans;
        if(ans)
        {
            cout<<"! "<<i<<endl;
            return;
        }
    }
    cout<<"? 1 3"<<endl;
    cin>> ans;
    if(ans){
        cout<<"! 1"<<endl;
        return;
    }
    cout<<"? 1 4"<<endl;
    cin>> ans;
    if(ans){
        cout<<"! 1"<<endl;
        return;
    }
    else cout<<"! 2"<<endl;
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