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
// void solve()
// {
//     int n, m, q, y, x, k;
//     cin >> n >> k >> q;
//     multiset<tuple<int, int, int>> mp;
//     vector<int> pap(n + 1, 1e9),overlapPoint;
//     for (int i = 0; i < q; i++)
//     {
//         int c, l, r;
//         cin >> c >> l >> r;
//         multiset<tuple<int, int, int>> mp1;
//         for (auto it = mp.begin(); it != mp.end();it++)
//         {
//             int cl = get<0>(*it);
//             int ll = get<1>(*it);
//             int rr = get<2>(*it);
//             if ((ll <= l && l <= rr) || (ll <= r && r <= rr))
//             { // overlap
//                 if ((cl == 1 && c == 2) || (cl == 2 && c == 1))
//                 {
//                     if (ll < l)
//                     {
//                         mp1.insert(make_tuple(cl, ll, l - 1));
//                         l = rr + 1;
//                     }
//                     if (rr > r)
//                     {
//                         mp1.insert(make_tuple(cl, r + 1, rr));
//                         r = ll - 1;
//                     }
//                 }
//                 else if (cl == 2 && c == 2)
//                 {
//                     l = min(l, ll);
//                     r = max(r, rr);
//                 }
//                 else if (cl == 1 && c == 1)
//                 {
//                     l = max(l, ll);
//                     r = min(r, rr);
//                 }
//             }
//             else
//             {
//                 mp1.insert(*it);
//             }
//         }
//         mp1.insert(make_tuple(c, l, r));
//         mp=mp1;
//     }

//     //cout << mp.size() << endl;
//     for (auto it : mp)
//     {
//         int cl = get<0>(it);
//         int ll = get<1>(it);
//         int rr = get<2>(it);
//         //cout << cl << " " << ll << " " << rr << endl;
//         int mex = 0;
//         if (cl == 2)
//         {
//             for (int i = ll; i <= rr; i++)
//             {
//                 pap[i] = mex;
//                 mex++;
//                 if(mex>=k) mex=0;
//             }
//         }
//         else
//         {
//             pap[ll] = k;
//         }
//     }
//     for (int i = 1; i <= n; i++)
//     {
//         cout << pap[i] << " ";
//     }
//     cout << endl;
// }

struct Constraint
{
    int id;
    int l, r;
};

void solve()
{
    int n, k, q;
    cin >> n >> k >> q;
    vector<bool> type1Seg(n + 1, false);
    vector<bool> type2Seg(n + 1, false);

    vector<Constraint> type2;

    for (int i = 0; i < q; i++)
    {
        int c, l, r;
        cin >> c >> l >> r;
        if (c == 1)
        {
            for (int j = l; j <= r; j++)
            {
                type1Seg[j] = true;
            }
        }
        else
        {
            type2.push_back({i, l, r});
            for (int j = l; j <= r; j++)
            {
                type2Seg[j] = true;
            }
        }
    }

    vector<int> a(n + 1, -1);
    int mex = 0;
    int prev = -1;
    sort(type2.begin(), type2.end(), [&](auto &x, auto &y)
         { return x.l < y.l; });
    for (auto &constr : type2)
    {
        int l = constr.l;
        int r = constr.r;
        if (prev < l)
        {
            mex = 0;
        }
        else
        {
            l = prev + 1;
        }
        for (int j = l; j <= r; j++)
        {
            if(type1Seg[j]) {
                mex=0;
                continue;
            }
            a[j] = mex;
            mex++;
            if (mex == k)
                mex = 0;
        }
        prev=max(prev, r);
    }

    for (int i = 1; i <= n; i++)
    {
        if (a[i] != -1)
        {
            cout << a[i] << " ";
        }
        else
        {
            if (type2Seg[i])
            {
                cout << k + 1 << " ";
            }
            else
            {
                cout << k << " ";
            }
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