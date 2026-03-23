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
int MOD = 1e9 + 7;
class DSU
{
public:
    int n;
    vector<int> p, rank;
    DSU(int sz)
    {
        p.assign(sz, 0);
        rank.assign(sz, 0);
        for (int i = 0; i < sz; i++)
            p[i] = i;
    }
    int find(int x)
    {
        if (p[x] == x)
            return x;
        return p[x] = find(p[x]);
    }
    void Unite(int x, int y)
    {
        int px = find(x);
        int py = find(y);
        if (px == py)
            return;
        if (rank[px] < rank[py])
        {
            p[px] = py;
        }
        else if (rank[px] > rank[py])
        {
            p[py] = px;
        }
        else
        {
            p[py] = px;
            rank[px]++;
        }
    }
};
class SegmentTree
{
public:
    int size;
    vector<int> tree;
    SegmentTree(int n)
    {
        size = 4 * n;
        tree.assign(size, 0);
    }
    void build(int idx, int l, int r, vector<int> &a)
    {
        if (l == r)
        {
            tree[idx] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * idx + 1, l, mid, a);
        build(2 * idx + 2, mid + 1, r, a);
        tree[idx] = tree[2 * idx + 1] ^ tree[2 * idx + 2];
    }
    int query(int idx, int l, int r, int i, int val, int &ans)
    {
        if (l == r && i == l)
        {
            return val;
        }
        int m = (l + r) / 2;
        if (m >= i)
        {
            int left = query(2 * idx + 1, l, m, i, val, ans);
            int right = tree[2 * idx + 2];
            if (right > left)
            {
                ans += (r - m);
            }
            return left ^ right;
        }
        else
        {
            int right = query(2 * idx + 2, m + 1, r, i, val, ans);
            int left = tree[2 * idx + 1];
            if (left >= right)
            {
                ans += (m - l + 1);
            }
            return left ^ right;
        }
    }
};
int findAns(int n,vector<int>& pap){
    map<int,int> mp;
    int mx=0;
    int ans=0;
    for(int i=0;i<n;i++){
        mp[pap[i]]++;
        if(mp[pap[i]]>1)
            mx=max(mx,pap[i]);
        ans+=pap[i];
        pap[i]=mx;    
    }
    return ans;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> pap(n);
    for (int i = 0; i < n; i++)
    {
        cin >> pap[i];
    }
    int ans = findAns(n, pap);
    ans += findAns(n, pap);
    int total=accumulate(pap.begin(), pap.end(), 0LL);
    for(int i=n-1;i>=0;i--){
        ans+=total;
        total-=pap[i];
    }
    cout << ans << "\n";
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