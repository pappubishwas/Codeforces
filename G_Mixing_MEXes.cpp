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
int dp[200005][3][3];
int dfs(int node, int parent, int prev, int sum, vector<vector<int>> &adj, string &s)
{
    if (dp[node][prev + 1][sum + 1] != -1)
    {
        return dp[node][prev + 1][sum + 1];
    }
    int res1 = 0;
    for (int &child : adj[node])
    {
        if (child != parent)
        {
            int res = 0;
            if (prev == -1)
            {
                if (s[child] == '?')
                {
                    res = max(res, dfs(child, node, 1, 0, adj, s));
                    res = max(res, dfs(child, node, 0, 0, adj, s));
                }
                else
                {
                    res = max(res, dfs(child, node, s[child] - '0', 0, adj, s));
                }
            }
            else
            {
                if (s[child] != '?')
                {
                    int nsum = sum;
                    if (s[child] - '0' != prev)
                    {
                        if (prev == 1)
                            nsum++;
                        else
                            nsum--;
                    }
                    res = max(res, dfs(child, node, s[child] - '0', nsum, adj, s));
                }
                else
                {
                    int nsum = sum;
                    if (1 == prev)
                    {
                        nsum++;
                    }
                    res = max(res, dfs(child, node, 0, nsum, adj, s));
                    nsum = sum;
                    if (prev == 0)
                        nsum--;
                    res = max(res, dfs(child, node, 1, nsum, adj, s));
                }
            }
            res1 += res;
        }
    }
    if (node != 0 && adj[node].size() == 1)
    {
        return sum != 0 ? 1 : 0;
    }
    return dp[node][prev + 1][sum + 1] = res1;
}
void solve()
{
    int n, m, s, x, q, k;
    cin >> n;
    vector<int> mex(n);
    vector<vector<int>> pap(n);
    vector<map<int,int>> mp(n);
    for (int i = 0; i < n; i++)
    {
        int len;
        cin>>len;
        for(int j=0;j<len;j++)
        {
            int val;
            cin>>val;
            pap[i].push_back(val);
            mp[i][val]++;
        }
        sort(pap[i].begin(),pap[i].end());
    }
    int total=0;
    map<int,int>cnt;
    for (int i = 0; i < n; i++)
    {
        int mx=0,inc=1;
        for(int j=0;j<pap[i].size();j++)
        {
            if(pap[i][j]==mx){
                mx++;
            }else if(pap[i][j]>mx){
                if((pap[i][j]-mx)==1){
                    inc++;
                    while(j+1<pap[i].size() && (pap[i][j+1]-pap[i][j])<=1){
                        if((pap[i][j+1]-pap[i][j])==1)
                            inc++;
                        j++;
                    }
                }
                break;
            }
        }
        
        total+=mx;
        cnt[mx]+=inc;
        mex[i]=mx;
    }
    int ans=0;
    for(int i=0;i<n;i++){
        int currMex=mex[i];
        for(int j=0;j<pap[i].size();j++){
            int newTotal=0;
            if(pap[i][j]<currMex && mp[i][pap[i][j]]==1){
                newTotal-=((currMex-pap[i][j])*(n-1));
            }
            if(cnt.count(pap[i][j]))
                newTotal+=cnt[pap[i][j]];
            newTotal+=((n-1)*total);    
            ans+=newTotal;
        }
    }
    cout<<ans<<endl;
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