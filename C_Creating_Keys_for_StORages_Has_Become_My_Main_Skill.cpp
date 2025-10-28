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

void Solve()
{
    int n, x;
    cin >> n>>x;
    vector<int> pap;
    if(n==1){
        cout<<x<<"\n";
        return;
    }else if(n==2){
        cout<<0<<" "<<x<<"\n";
        return;
    }
    int temp=x;
    int bitCount=0;
    while(temp>0){
        if(temp & 1) bitCount++;
        else break;
        temp>>=1;
    }
    int s=0;
    int limit=(1LL<<bitCount)-1;
    while(n>0 && s<=limit){
        pap.push_back(s);
        s++;
        n--;
    }
    if(n>0){
        while(n>0){
            pap.push_back(x);
            n--;
        }
    }else{
        int last=pap.back();
        if(binaryLength(last)!=binaryLength(x)){
            pap.pop_back();
            pap.push_back(x);
        }
    }
    for(auto &val:pap){
        cout<<val<<" ";
    }
    cout<<"\n";
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
        Solve();
    }

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}