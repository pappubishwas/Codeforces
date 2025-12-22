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
// const int mod = 998244353;
// const int MOD = 1e9 + 7;
// int rndRange(int l, int r) { return RNG() % (r - l + 1) + l; }
// int fact[200001];
// int powerl(int a, int b)
// {
//     int res = 1;
//     while (b)
//     {
//         if (b & 1)
//             res = res * a % mod;
//         a = a * a % mod;
//         b >>= 1;
//     }
//     return res;
// }
// int inMod(int a)
// {
//     return powerl(a, mod - 2);
// }

// vector<int> seg;
// void build(int idx, int l, int r, vector<int> &d)
// {
//     if(l>r) return;
//     if (l == r)
//     {
//         seg[idx] = d[l];
//         return;
//     }
//     int m = (l + r) / 2;
//     build(2 * idx + 1, l, m, d);
//     build(2 * idx + 2, m + 1, r, d);
//     seg[idx] = __gcd(seg[2 * idx + 1], seg[2 * idx + 2]);
// }

// int query(int idx, int l, int r, int ql, int qr)
// {
//     if (ql > r || l > qr || l > r)
//         return 0;
//     if (ql <= l && r <= qr)
//         return seg[idx];
//     int m = (l + r) / 2;
//     return __gcd(query(2 * idx + 1, l, m, ql, qr), query(2 * idx + 2, m + 1, r, ql, qr));
// }

// void Solve()
// {
//     int n, k, q;
//     cin >> n >> q;
//     vector<int> pap(n), d(n);
//     seg.resize(4 * n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> pap[i];
//     }
//     for (int i = 0; i < n - 1; i++)
//     {
//         d[i] = abs(pap[i + 1] - pap[i]);
//     }

//     build(0, 0, n - 2, d);
//     for (int i = 0; i < q; i++)
//     {
//         int l, r;
//         cin >> l >> r;
//         if (l == r)
//         {
//             cout << 0 << " ";
//         }
//         else
//         {
//             int ans = query(0, 0, n - 2, l - 1, r - 2);
//             cout << ans << " ";
//         }
//     }
//     cout << endl;
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







//using sparse table

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
const int mod = 998244353;
const int MOD = 1e9 + 7;
int rndRange(int l, int r) { return RNG() % (r - l + 1) + l; }
int fact[200001];
int powerl(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
int inMod(int a)
{
    return powerl(a, mod - 2);
}


vector<vector<int>> spt;
vector<int> blog;
int LOG;
int query(int l, int r)
{
    int len=r-l+1;
    int k=blog[len];
    return __gcd(spt[l][k],spt[r-(1LL<<k)+1][k]);
}

void Solve()
{
    int n, k, q;
    cin >> n >> q;
    vector<int> pap(n), d(n);
    blog.assign(n+1,0);
    blog[1]=0;
    for(int i=2;i<=n;i++){
        blog[i]=blog[i/2]+1;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> pap[i];
    }
    LOG=blog[n];
    spt.assign(n,vector<int>(LOG+1));
    for (int i = 0; i < n - 1; i++)
    {
        d[i] = abs(pap[i + 1] - pap[i]);
        spt[i][0]=d[i];
    }

    for(int k=1;k<=LOG;k++){
        for(int i=0;i+(1LL<<k)-1<n-1;i++){
            spt[i][k]=__gcd(spt[i][k-1],spt[i+(1LL<<(k-1))][k-1]);
        }
    }


    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        if (l == r)
        {
            cout << 0 << " ";
        }
        else
        {
            int ans = query(l - 1, r - 2);
            cout << ans << " ";
        }
    }
    cout << endl;
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