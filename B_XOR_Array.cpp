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


void Solve()
{
    int n, k,l,r;
    cin >> n >>l>>r;
    vector<int>pre(n+1);
    for(int i=0;i<=n;i++)
    {
        pre[i]=i; // prefix xor of all elements from 0 to i is i, all prefix xor are different
    }
    pre[r]=pre[l-1]; // l-r subarray prefix xor will be zero, only if prefix xor of rth and l-1th are equal

    for(int i=1;i<=n;i++){
        cout<<(pre[i]^pre[i-1])<<" "; // p0,p1, p2 p3 .... a1=p1^p0 , a2=p2^p1 so on, because p1=p0^a1, we know x^y=z then z^y=x or z^x=y
    }
    cout<<endl;
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