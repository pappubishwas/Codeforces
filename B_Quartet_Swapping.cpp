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

int inversion(vector<int> &arr)
{
    int invCount = 0;
    int n = arr.size();
    ordered_set<int> os;
    for (int i = 0; i < n; i++)
    {
        invCount += i - os.order_of_key(arr[i]);
        os.insert(arr[i]);
    }
    return invCount;
}

void Solve()
{
    int n, q;
    cin >> n;
    vector<int> pap(n), odd, even;
    for (int i = 0; i < n; i++)
    {
        cin >> pap[i];
        if (i % 2)
            odd.push_back(pap[i]);
        else
            even.push_back(pap[i]);
    }
    int oddInv = inversion(odd);
    int evenInv = inversion(even);
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());
    for (int i = 0; i < n - 3; i++)
    {
        if (i % 2 == 1)
            cout << odd[i / 2] << " ";
        else
            cout << even[i / 2] << " ";
    }
    if (n % 2)
    {
        if (oddInv % 2 == evenInv % 2)
            cout << even[even.size() - 2] << " " << odd.back() << " " << even[even.size() - 1] << "\n";
        else
            cout << even[even.size() - 1] << " " << odd.back() << " " << even[even.size() - 2] << "\n";
    }
    else
    {

        if (oddInv % 2 == evenInv % 2)
            cout << odd[odd.size() - 2] << " " << even[even.size() - 1] << " " << odd.back() << "\n";
        else
        {
            cout << odd.back() << " " << even[even.size() - 1] << " " << odd[odd.size() - 2] << "\n";
        }
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