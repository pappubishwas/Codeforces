#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long
#define INF (int)1e18
const int MOD = 998244353;
const int N = 2e5 + 5;

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int fact[N], invFact[N];

// fast exponentiation for modular inverse
int modpow(int a, int b)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void precompute()
{
    fact[0] = 1;
    for (int i = 1; i < N; i++)
        fact[i] = fact[i - 1] * i % MOD;
    invFact[N - 1] = modpow(fact[N - 1], MOD - 2);
    for (int i = N - 2; i >= 0; i--)
        invFact[i] = invFact[i + 1] * (i + 1) % MOD;
}

void Solve()
{
    int n;
    cin >> n;
    vector<int> pap(n);
    for (int i = 0; i < n; i++)
        cin >> pap[i];

    if (accumulate(pap.begin(), pap.end(), 0LL) != n)
    {
        cout << 0 << "\n";
        return;
    }

    int ans = 1;

    if (n & 1)
    { // odd
        if (accumulate(pap.begin() + (n / 2 + 1), pap.end(), 0LL) != 0)
        {
            cout << 0 << "\n";
            return;
        }
        int sum = 0;
        for (int i = n / 2; i >= 0; i--)
        {
            int cnt = 2 * (n / 2 - i) + 1 - sum;
            if (cnt < pap[i])
            {
                cout << 0 << "\n";
                return;
            }
            ans = ans * fact[cnt] % MOD * invFact[cnt - pap[i]] % MOD * invFact[pap[i]] % MOD;
            sum += pap[i];
        }
        cout << ans % MOD << "\n";
    }
    else
    { // even
        if (accumulate(pap.begin()+n/2, pap.end(), 0LL) != 0)
        {
            cout << 0 << "\n";
            return;
        }
        int sum = 0;
        for (int i = n / 2 - 1; i >= 0; i--)
        {
            int cnt = 2 * (n / 2 - i) - sum;
            if (cnt < pap[i])
            {
                cout << 0 << "\n";
                return;
            }
            ans = ans * fact[cnt] % MOD * invFact[cnt - pap[i]] % MOD * invFact[pap[i]] % MOD;
            sum += pap[i];
        }
        cout << ans % MOD << "\n";
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    precompute();

    int t = 1;
    cin >> t;
    while (t--)
        Solve();
}
