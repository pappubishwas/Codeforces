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
    int n, m,q, k;
    cin >> n>>q;
    vector<int> pap(n+1);
    for(int i=1;i<=n;i++) cin>>pap[i];
    string s;
    cin>> s;
    s="R"+s;
    set<int> idx;
    int mx=0;
    vector<bool> possible(n+1,true);
    for(int i=1;i<n;i++){
        mx=max(mx,pap[i]);
        if(mx!=i){
            possible[i]=false;
            if(s[i]=='L' && s[i+1]=='R'){
                idx.insert(i);
            }
        }
    }
    while(q--){
        int pos;
        cin>>pos;
        if(idx.find(pos)!=idx.end()) idx.erase(pos);
        if(idx.find(pos-1)!=idx.end()) idx.erase(pos-1);
        s[pos]=(s[pos]=='L') ? 'R':'L';
        if(s[pos-1]=='L' && s[pos]=='R' && !possible[pos-1]){
            idx.insert(pos-1);
        }
        if(s[pos]=='L' && s[pos+1]=='R' && !possible[pos]){
            idx.insert(pos);
        }
        if(idx.empty()){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
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