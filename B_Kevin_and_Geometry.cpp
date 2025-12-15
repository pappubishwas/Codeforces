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

vector<int> lp;
vector<int> pr;
int N = 10000000;

void Solve()
{
    int n, l, r, m;
    cin >> n;
    vector<int> pap(n);
    map<int, int> mp;
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        cin >> pap[i];
        mp[pap[i]]++;
    }
    for (auto &it : mp)
    {
        if (it.second >= 2)
        {
            s.insert(it.first);
        }
        if (it.second >= 4)
        {
            cout << it.first << " " << it.first << " " << it.first << " " << it.first << endl;
            return;
        }
    }
    if (s.size() >= 2)
    {
        cout << *s.begin() << " " << *s.begin() << " " << *next(s.begin()) << " " << *next(s.begin()) << endl;
    }
    else if (s.size() == 0)
    {
        cout << -1 << endl;
    }
    else
    {
        sort(pap.begin(), pap.end());

        int x = *s.begin();
        auto it = find(pap.begin(), pap.end(), x);
        pap.erase(it);

        it = find(pap.begin(), pap.end(), x);
        pap.erase(it);

        int need = 2 * (*s.begin());
        for (int i = 0; i < n - 3; i++)
        {
            if ((pap[i + 1] - pap[i]) < need)
            {
                cout << *s.begin() << " " << *s.begin() << " " << pap[i] << " " << pap[i + 1] << endl;
                ;
                return;
            }
        }
        cout << -1 << endl;
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