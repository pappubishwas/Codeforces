// #include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace std;
// using namespace __gnu_pbds;
// #define int long long
// #define INF (int)1e18
// mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
// template <class T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// const int MOD = 1e9 + 7;
// int rndRange(int l, int r) { return RNG() % (r - l + 1) + l; }
// int powerl(int a, int b)
// {
//     int res = 1;
//     while (b)
//     {
//         if (b & 1)
//             res = res * a % MOD;
//         a = a * a % MOD;
//         b >>= 1;
//     }
//     return res;
// }
// int inMod(int a)
// {
//     return powerl(a, MOD - 2);
// }

// void Solve()
// {
//     int m, n;
//     cin >> n;
//     vector<int> pap(n+1),b(n+1);
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> pap[i];
//     }
//     vector<vector<pair<int,int>>> adj(n+1);
//     for (int i = 1; i <=n; i++)
//     {
//         cin >> b[i];
//         adj[i].push_back({b[i],pap[i]});
//         if(i>1){
//             adj[i].push_back({i-1,0});
//         }
//     }
//     vector<int> dp(n+1,INF);
//     dp[1]=0;
//     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
//     pq.push({0,1});
//     while (!pq.empty())
//     {
//         int u=pq.top().second;
//         int cost=pq.top().first;
//         pq.pop();
//         if(cost>dp[u]) continue;
//         for(auto& it:adj[u]){
//             if(dp[it.first]>it.second+cost){
//                 dp[it.first]=it.second+cost;
//                 pq.push({dp[it.first],it.first});
//             }
//         }
//     }
//     int curr=0,ans=0;
//     for(int i=1;i<=n;i++){
//         curr+=pap[i];
//         ans=max(ans,curr-dp[i]);
//     }
//     cout<<ans<<endl;
// }
// int32_t main()
// {
//     auto begin = chrono::high_resolution_clock::now();
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     int t = 1;
//     cin >> t;

//     for (int i = 1; i <= t; i++)
//     {
//         Solve();
//     }

//     auto end = chrono::high_resolution_clock::now();
//     auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
//     return 0;
// }




#include<bits/stdc++.h>
using namespace std;

#define int long long

struct segmenttree
{
    int n;
    vector<int> st, lazy;

    void init(int _n)
    {
        this->n = _n;
        st.resize(4 * n, LLONG_MAX);
        lazy.resize(4 * n, LLONG_MAX);
    }

    void push(int start, int ending, int node)
    {
        if (lazy[node] != LLONG_MAX)
        {
            st[node] = min(lazy[node], st[node]);

            if (start != ending)
            {
                lazy[2 * node + 1] = min(lazy[2 * node + 1],lazy[node]);
                lazy[2 * node + 2] = min(lazy[node], lazy[2 * node + 2]);
            }

            lazy[node] = LLONG_MAX;
        }
    }

    int query(int start, int ending, int l, int r, int node)
    {
        push(start, ending, node);

        if (start > r || ending < l)
        {
            return LLONG_MAX;
        }

        if (start >= l && ending <= r)
        {
            return st[node];
        }

        int mid = (start + ending) / 2;

        int q1 = query(start, mid, l, r, 2 * node + 1);
        int q2 = query(mid + 1, ending, l, r, 2 * node + 2);

        return min(q1, q2);
    }

    void update(int start, int ending, int node, int l, int r, int value)
    {
        push(start, ending, node);

        if (start > r || ending < l)
        {
            return;
        }

        if (start >= l && ending <= r)
        {
            lazy[node] = min(lazy[node], value);
            push(start, ending, node);            
            return;
        }

        int mid = (start + ending) / 2;

        update(start, mid, 2 * node + 1, l, r, value);

        update(mid + 1, ending, 2 * node + 2, l, r, value);

        st[node] = min(st[node * 2 + 1], st[node * 2 + 2]);

        return;
    }

    int query(int l, int r)
    {
        return query(0, n - 1, l, r, 0);
    }

    void update(int l, int r, int x)
    {
        update(0, n - 1, 0, l, r, x);
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    int tt; cin >> tt;

    while(tt--) {
        int n; cin >> n;
        vector<int>a(n), b(n);

        for(auto &i : a) cin >> i;
        for(auto &i : b) cin >> i;

        segmenttree tree; tree.init(n); tree.update(0, 0, 0);

        int sum = 0, answer = 0;

        for(int i = 0; i < n; i++) {
            sum += a[i];
            int query = tree.query(i, i);
            if(query == LLONG_MAX) break;
            else {
                answer = max(answer, sum - query);
                tree.update(0, b[i] - 1, query + a[i]);
            }
        }

        cout << answer << "\n";
    }
}







