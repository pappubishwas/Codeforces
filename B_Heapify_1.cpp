#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve() 
{
int n; cin >> n;
    
    vector <int> a(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    
    for (int x = 1; x <= n/2; x += 2){
        vector <int> b;
        for (int i = x; i <= n; i *= 2){ // after n/2 , it will take one element only
            b.push_back(a[i]);
        }
        
        sort(b.begin(), b.end()); // this all elements can be sorted in any order, so we sort them and put them in the right place
        int p = 0;
        
        for (int i = x; i <= n; i *= 2){
            a[i] = b[p++];
        }
    }
    
    for (int i = 1; i <= n; i++){
        if (a[i] != i){
            cout << "NO\n";
            return;
        }
    }
    
    cout << "YES\n";
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