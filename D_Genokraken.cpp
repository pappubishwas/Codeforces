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
    int n;
    cin >> n;
    vector<int> ans(n, -1);
    ans[1] = 0;
    vector<int> curr;
    int next = n;
    curr.push_back(1);
    for (int i = 2; i < n; i++)
    {
        cout << "? 1 " << i << endl;
        int x;
        cin >> x;
        if (x)
        {
            ans[i] = 0;
            curr.push_back(i);
        }
        else
        {
            ans[i] = 1;
            next = i;
            break;
        }
    }
    if (curr.size() == 1)
    {
        while (next < n)
        {
            ans[next] = curr[0];
            curr[0] = next;
            next++;
        }
    }
    while (n > 4 && !curr.empty() && next < n)
    {
        vector<int> temp;
        for (int i = 0; i < curr.size() && next < n; i++)
        {
            cout << "? " << curr[i] << " " << next << endl;
            int x;
            cin >> x;
            if (x == 0)
            {
                ans[next] = curr[i];
                temp.push_back(next);
                next++;
            }
        }
        if (temp.size() == 1)
        {
            while (next < n)
            {
                ans[next] = temp[0];
                temp[0] = next;
                next++;
            }
            break;
        }
        curr = temp;
    }
    cout << "! ";
    for (int i = 1; i < n; i++)
        cout << ans[i] << " ";
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