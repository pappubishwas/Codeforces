#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve() 
{
    int n; cin >> n;
    
    // n even is trivial 
    // n odd => need to find a triplet of good things 
    // x, y, z where x + y = z and x, y, z are all perfect squares 
    // a^2 + b^2 = c^2 
    // 9, 16, 25 
    
    // 1, 10, 26 
    // 25 cant be matched? 
    // match with 29 
    // 27 and 28 good 
    // so n >= 29 is solved
    
    // can 27 be solved actually? 
    
    if (n % 2 == 0){
        for (int i = 1; i <= n; i += 2){
            cout << ((i + 1) / 2) << " " << ((i + 1) / 2) << " ";
        }
        cout << "\n";
    } else if (n <= 25){
        cout << -1 << "\n";
    } else {
        int col = 1;
        vector <int> a(n + 1);
        a[1] = a[10] = a[26] = col++;
        a[27] = a[23] = col++;
        a[24] = a[25] = col++;
        
        for (int i = 11; i < 23; i += 2){
            a[i] = a[i + 1] = col++;
        }
        for (int i = 2; i < 10; i += 2){
            a[i] = a[i + 1] = col++;
        }
        for (int i = 28; i <= n; i += 2){
            a[i] = a[i + 1] = col++;
        }
        
        for (int i = 1; i <= n; i++){
            cout << a[i] << " \n"[i == n];
        }
    }
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
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}