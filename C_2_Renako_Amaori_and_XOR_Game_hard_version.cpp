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

// void solve() {
//     int n;
//     cin >> n;

//     vector<int> a(n), b(n);
//     for (int i = 0; i < n; i++) cin >> a[i];
//     for (int i = 0; i < n; i++) cin >> b[i];

//     int diffXor = 0;
//     for (int i = 0; i < n; i++) diffXor ^= (a[i] ^ b[i]);

//     if (diffXor == 0) {
//         cout << "Tie\n";
//         return;
//     }

//     int msb = 0;
//     for (int bit = 20; bit >= 0; bit--) {
//         if ((diffXor >> bit) & 1) {
//             msb = bit;
//             break;
//         }
//     }

//     int lastIdx = -1;
//     for (int i = 0; i < n; i++) {
//         int x = (a[i] >> msb) & 1;
//         int y = (b[i] >> msb) & 1;
//         if (x != y) lastIdx = i + 1;
//     }

//     if (lastIdx & 1) cout << "Ajisai\n";
//     else cout << "Mai\n";
// }

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    vector<int> bitCount(32);
    for (int i = 0; i < n; i++)
    {
        for (int bit = 31; bit >= 0; bit--) // counting all the bits based on the position
        {
            if (a[i] & (1 << bit)) // cheking bit is set or not in the a , if set then count that bit 
                bitCount[bit]++;
            if (b[i] & (1 << bit)) // same as be
                bitCount[bit]++;
        }
    }
    int msb = -1;
    for (int bit = 31; bit >= 0; bit--) // finding the MSB bit with odd count , becase even count will not effect the result
    {
        if (bitCount[bit] % 2) // msb found with odd count
        {
            msb = bit;
            break;
        }
    }
    if (msb == -1) // all bits are even number of times so tie
    {
        cout << "Tie" << endl;
        return;
    }
    int last = -1;
    for (int i = 0; i < n; i++)
    {
        if (((a[i] >> msb) & 1) != ((b[i] >> msb) & 1)) // finding , who played the last move of the msb same as c1
            last = i + 1;
    }
    if (last % 2) // odd index for ajisai
        cout << "Ajisai" << endl;
    else
        cout << "Mai" << endl;
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