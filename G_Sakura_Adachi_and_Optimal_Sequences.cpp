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

const int MOD = 1000003;
const int MAXV = 1000003;

vector<int> fact, invFact;

int power(int base, int exp)
{
    int res = 1;
    base %= MOD;
    while (exp)
    {
        if (exp & 1)
            res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return res;
}

int modInv(int x)
{
    return power(x, MOD - 2);
}

void init()
{
    fact.resize(MAXV);
    invFact.resize(MAXV);

    fact[0] = 1;
    for (int i = 1; i < MAXV; i++)
        fact[i] = (fact[i - 1] * i) % MOD;

    invFact[MAXV - 1] = modInv(fact[MAXV - 1]);
    for (int i = MAXV - 2; i >= 0; i--)
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
}

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int &x : a)
        cin >> x;
    for (int &x : b)
        cin >> x;

    int bestOps = -1, ways = 0;

    for (int k = 0; k <= 20; k++)
    {
        bool ok = true;
        for (int i = 0; i < n; i++)
        {
            if ((int)a[i] * (1LL << k) > b[i])
            {
                ok = false;
                break;
            }
        }
        if (!ok)
            break;

        int ops = k;
        vector<int> stageCnt(k + 1, 0);
        int denom = 1;

        for (int i = 0; i < n; i++)
        {
            int diff = b[i] - a[i] * (1 << k);
            int c0 = diff >> k;

            stageCnt[0] += c0;
            ops += c0;
            denom = (denom * invFact[c0]) % MOD;

            int rem = diff & ((1 << k) - 1);
            for (int bit = 0; bit < k; bit++)
            {
                if (rem & (1 << bit))
                {
                    stageCnt[k - bit]++;
                    ops++;
                }
            }
        }

        int curWays = 1;
        for (int j = 0; j <= k; j++)
        {
            if (stageCnt[j] >= MOD)
            {
                curWays = 0;
                break;
            }
            curWays = (curWays * fact[stageCnt[j]]) % MOD;
        }

        curWays = (curWays * denom) % MOD;

        if (bestOps == -1 || ops < bestOps)
        {
            bestOps = ops;
            ways = curWays;
        }
        else if (ops == bestOps)
        {
            ways = (ways + curWays) % MOD;
        }
    }

    cout << bestOps << " " << ways << "\n";
}

int32_t main()
{
    auto begin = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);
    init();
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