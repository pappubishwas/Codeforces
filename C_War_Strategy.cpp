#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define INF (int)1e18
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int MOD = 1e9 + 7;
int rndRange(int l, int r) { return RNG() % (r - l + 1) + l; }
int powerl(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
int inMod(int a)
{
    return powerl(a, MOD - 2);
}

void Solve()
{
    int n, day,q, idx;
    cin>> n>>day>>idx;
    int ans=1,curr=1;
    while(true){
        int left=idx-curr;
        int right=idx+curr;
        if(left<=0 || right>n){
            break;
        }
        int total=3LL*curr-1;
        if(total<=day){
            ans=2LL*curr+1;
        }else{
            total--;
            if(total<=day){
                ans=2LL*curr;
            }else{
                break;
            }
        }
        curr++;
    }
    if (curr >= idx) {
       
        int left = idx - 1; 
        while (true) {
            int right = idx + curr;
            if (right > n) break;
            int total = left + curr + curr - 1; 
            if (total <= day) {
                ans = left + 1 + curr;
            } else break;
            curr++;
        }
    } else {

        int right = n - idx; 
        
        while (true) {
            int left = idx - curr;
            if (left <= 0) break;
            int total = right + curr + curr - 1; 
            if (total <= day) {
                ans = right + 1 + curr;
            } else break;
            curr++;
        }
    }
    cout << ans << endl;
}
int32_t main()
{
    auto begin = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        Solve();
    }

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    return 0;
}