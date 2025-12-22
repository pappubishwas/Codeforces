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
void Solve()
{
    int n, k;
    cin >> n;
    vector<int> pap(n);
    for (auto &x : pap)
        cin >> x;
    if (n == 1 || n == 2)
        cout << n - 1 << endl;
    else
    {
        int low = 0, high = pap[1] - pap[0];
        int ans = 0;
        pap.push_back(1e15);
        //cout<<pap.back()<<endl;
        for (int i = 1; i < n; i++)
        {
            int minr = pap[i] - pap[i - 1] - high;
            int nhigh = pap[i] - pap[i - 1] - low;
            int maxr = pap[i + 1] - pap[i];
            if (minr >= maxr) // nlow means minimum r needs for current point, and currdist means this point max radius can take, so if min r is greater than maxr
            {
                minr = 0;
            }
            else // pair possible , min radius needs and enoguh space to cover 
            {
                ans++;
            }
            high = min(nhigh, maxr); 
            low = minr;
        }
        cout << ans << endl;
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