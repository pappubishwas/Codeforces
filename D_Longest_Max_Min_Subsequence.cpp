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


// void solve()
// {
//     int n;
//     cin >> n;
//     vector<int> a(n);
//     for (int i = 0; i < n; i++) cin >> a[i];
    
//     map<int, int> mp;
//     for (int i = n - 1; i >= 0; i--) {
//         if (!mp.count(a[i])) mp[a[i]] = i;
//     }
    
//     vector<int> ans;
//     vector<bool> vis(n + 1, false);
//     auto better = [](int x, int y, bool odd) {
//         return odd ? x > y : x < y;
//     };
//     for (int i = 0; i < n; i++)
//     {
//         if (vis[a[i]]) continue; 

//         while (!ans.empty()) {
//             int m = (int)ans.size();
//             if (mp[ans[m - 1]]>i && better(a[i], ans[m - 1], m & 1)) {
//                 vis[ans[m - 1]] = false;
//                 ans.pop_back();
//             }
//             else if (m > 1 && mp[ans[m - 2]]>i && mp[ans[m - 1]]>i && better(a[i], ans[m - 2], (m - 1) & 1)) {
//                 vis[ans[m - 2]] = false;
//                 vis[ans[m - 1]] = false;
//                 ans.pop_back();
//                 ans.pop_back();
//             }
//             else {
//                 break;
//             }
//         }
        
//         ans.push_back(a[i]);
//         vis[a[i]] = true;
//     }
//     cout << ans.size() << endl;
//     for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
//     cout << endl;
// }



void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    map<int, int> mp;
    for (int i = n - 1; i >= 0; i--) {
        if (!mp.count(a[i])) mp[a[i]] = i;
    }
    
    vector<int> ans;
    vector<int> vis(n + 1, 0);
    
    for (int i = 0; i < n; i++)
    {
        if (vis[a[i]]) continue; 

        while (ans.size() > 0) {

            if ((ans.size() % 2 == 1 && ans.back() < a[i] && mp[ans.back()] > i) || (ans.size() % 2 == 0 && ans.back() > a[i] && mp[ans.back()] > i))
            {
                vis[ans.back()] = 0;
                ans.pop_back();
            }
            else if(ans.size() > 1 && ((ans.size() % 2 == 0 && 
                    ans[ans.size()-2] < a[i] && 
                    mp[ans[ans.size()-2]] > i && mp[ans.back()] > i) || (ans.size() % 2 == 1 && 
                    ans[ans.size()-2] > a[i] && 
                    mp[ans[ans.size()-2]] > i && mp[ans.back()] > i))) {
                
                vis[ans.back()] = 0;
                ans.pop_back();
                vis[ans.back()] = 0;
                ans.pop_back();
            }
            else break;
        }
        
        ans.push_back(a[i]);
        vis[a[i]] = 1;
    }
    
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    cout << endl;
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