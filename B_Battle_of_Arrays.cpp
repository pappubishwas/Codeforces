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
const int MOD = 1e9 + 7;
int rndRange(int l, int r) { return RNG() % (r - l + 1) + l; }
int powerl(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
int inMod(int a)
{
    return powerl(a, MOD - 2);
}

void Solve()
{
    int n, m;
    cin >> n >> m;
    priority_queue<int> alice, bob;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        alice.push(a);
    }
    for (int i = 0; i < m; i++)
    {
        int b;
        cin >> b;
        bob.push(b);
    }
    bool turn = true;
    while (!bob.empty() && !alice.empty())
    {
        int a = alice.top();
        int b = bob.top();
        if (turn)
        {
            bob.pop();
            if (b > a)
            {
                bob.push(b - a);
            }
        }
        else
        {
            alice.pop();
            if (b < a)
            {
                alice.push(a - b);
            }
        }
        turn = !turn;
    }
    if (bob.empty())
    {
        cout << "Alice" << endl;
    }else{
         cout << "Bob" << endl;
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