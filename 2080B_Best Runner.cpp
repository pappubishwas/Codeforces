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

void Solve()
{
    int n, k, x, m, T;
    cin >> n >> m >> T;
    vector<int> a(n+1), b(m), prefix(n + 1);
    for (int i=1;i<=n;i++)
        cin >> a[i];
    for (auto &p : b)
        cin >> p;
    for (int i = 1; i <= n; i++)
    {
        prefix[i] += prefix[i - 1] + a[i];
    }

    int ans = 0;
    for (int i = 1; i <=n; i++)
    {
        int idx = upper_bound(b.begin(), b.end(), i) - b.begin();
        if(idx==m) idx--;
        int j = b[idx];

        int need = 0;
        if (i < j){
            need = prefix[j] - prefix[i-1];
            //cout<<j<<endl;
        }else
        {
            need = prefix[i] - prefix[j - 1];
            //cout << need << endl;
        }

        need=T-need;
        //cout<<need<<endl;
        if (need >= 0)
        {
            ans = max(ans, ((need) / a[i] +abs(i-j)+1LL));
        }
        if (idx > 0)
        {
            j = b[idx - 1];
            need = T - (prefix[i] - prefix[j - 1]);
            if (need >= 0)
            {
                ans = max(ans, ((need) / a[i] + abs(i - j)+1LL));
            }
        }
    }
    cout << ans<<endl;
}

int32_t main()
{
    auto begin = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;

    for (int i = 1; i <= t; i++)
    {
        Solve();
    }

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    return 0;
}