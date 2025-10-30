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

int rndRange(int l, int r) { return RNG() % (r - l + 1) + l; }

int binaryLength(int n)
{
    return 64 - __builtin_clzll(n);
}
int mod = 998244353;
int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
int res=INF;
bool check(int curr){
    while(curr>0){
        if(curr%10==7){
            return true;
        }
        curr/=10;
    }
    return false;
}

void dfs(int curr,int depth){
    if(check(curr) || depth>=7){
        res=min(res,depth);
        return;
    }
    if(res < depth) return;
    int sum=0;
    for(int i=1;i<=9;i++){
        sum=sum*10+9;
        dfs(sum+curr,depth+1);
    }
   
}
void solve()
{
    int n, m;
    cin >> n ;
    res=7;
    int d=9;
    for(int i=0;i<9;i++){
        int s=n;
        int c=0;
        for(int k=0;k<7;k++){
            if(check(s)) break;
            c++;
            s+=d;
        }
        res=min(res,c);
        d=d*10+9;
    }
    cout<<res<<"\n";
}

int32_t main()
{
    auto begin = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);

    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}