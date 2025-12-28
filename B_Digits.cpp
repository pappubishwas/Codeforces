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
    int n, l, r, d;
    cin >> n >> d;
    cout << 1;
    if (n >= 3 || d % 3 == 0)
    { // n>=3 for n always have a multiple of 3 (total number of digits are n!*d ), it will be multiple of 3 that makes the whole number divisible by 3
        cout << " " << 3;
    }
    if (d == 5)
    { // if last digit is 5 then the whole number is divisible by 5
        cout << " " << 5;
    }
    if (n >= 3 || d == 7)
    {
        cout << " " << 7;
    }
    if (n >= 6 || d % 9 == 0)
    {
        cout << " " << 9; // n>=6 for n always have a multiple of 9 (total number of digits are n!*d ), it will be multiple of 9 that makes the whole number divisible by 9
    }
    else
    { // check manually
        int fact = 1;
        for (int i = 2; i <= n; i++)
        {
            fact = (fact * i) % 9;
        }
        if (d * fact % 9 == 0)
        {
            cout << " " << 9;
        }
    }
    cout << "\n";
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