#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")

using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define f(i, n) for (ll i = 0; i < n; i++)
#define ia(a, n) \
    ll a[n];     \
    f(i, n) cin >> a[i]
#define iv(v, n)     \
    vector<ll> v(n); \
    f(i, n) cin >> v[i]
#define MOD (1000000007)
#define INF 1000000000000000000LL // Infinity for ll
#define mp make_pair
#define nline '\n'
#define yes cout << "YES\n"
#define no cout << "NO\n"

template <typename T>
using os = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
using oms = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

// read question properly
// don't forget newlines!!!!!!
// take care about cin >> t;
// comment the optimization before debugging
// ALWAYS USE FIXED << SETPRECISION WHILE OUTPUTTING FLOATS

void solve()
{
    int n;
    cin >> n;
    int a[n], b[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    
    int premin[n], postmax[n];
    premin[0] = a[0];
    for(int i = 1; i < n; i++) {
        premin[i] = min(premin[i-1], a[i]);
    }
    
    postmax[n-1] = a[n-1];
    
    for(int i = n-2; i >= 0; i--) {
        postmax[i] = max(postmax[i+1], a[i]);
    }
    
    int low = 0, high = n-1;
    while(low < high) {
        int mid = (low + high + 1)/2;

        int p2 = 0;
        int mi = premin[mid-1];
        bool flag = true;
        for(int i = 0; i < mid; i++) {
            int cur;
            if(a[i] == mi && mi < postmax[mid]) cur = postmax[mid];
            else cur = a[i];
            while(p2 < n && b[p2] > cur) {
                p2++;
            }
            if(p2 == n) {
                flag = false;
                break;
            }
        }
        if(p2 > n - mid) {
            flag = false;
        }

        if(flag) {
            low = mid;
        }
        else{
            high = mid - 1;
        }
    }

    if(*min_element(a,a+n) > b[0]) {
        cout << n << '\n';
    }
    else{
        cout << low << '\n';
    }
}

int main()
{
#ifdef PRADY
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    clock_t T = clock();
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }

#ifdef PRADY
    cout << "\nTime taken: " << ((float)(clock() - T)) / CLOCKS_PER_SEC << " seconds";
#endif
    return 0;
}