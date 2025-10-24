
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

int binaryLength(int n)
{
    if (n == 0) return 1;
    return 64 - __builtin_clzll(n);
}

int que()
{
    int n;
    cin >> n;
    if (n == -1) exit(0); 
    return n;
}

void Solve()
{
    int n;
    cin >> n;

    int ans = 0;
    vector<int> indices(n - 1);
    iota(indices.begin(), indices.end(), 1); 
    
    vector<int> values(n);
    iota(values.begin(), values.end(), 1); 

    for (int k = 0; k < 18; k++) {
        if (values.size() == 1) {
            break;
        }

        int x = (1LL << k); 

        vector<int> indicesZero, indicesOne;
        vector<int> valuesZero, valuesOne;

        int countOne = 0;
        
        for (int i : indices) {
            cout << "? " << i << " " << x << endl;
            int res = que();
            if (res == 1) { 
                indicesOne.push_back(i);
                countOne++;
            } else {
                indicesZero.push_back(i);
            }
        }

        int totalCount = 0;
        
        for (int val : values) {
            if ((val & x) != 0) {
                valuesOne.push_back(val);
                totalCount++;
            } else { 
                valuesZero.push_back(val);
            }
        }

        if (countOne < totalCount) {
            ans |= x;
            indices = indicesOne; 
            values = valuesOne;   
        } else {
            indices = indicesZero; 
            values = valuesZero;   
        }
    }

    ans = values[0];
    cout << "! " << ans << endl;
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
        Solve();
    }

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}