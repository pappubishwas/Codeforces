// #include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// // #pragma GCC optimize("Ofast")
// // #pragma GCC optimize("unroll-loops")

// using namespace std;
// using namespace __gnu_pbds;

// #define ll long long
// #define f(i, n) for (ll i = 0; i < n; i++)
// #define ia(a, n) \
//     ll a[n];     \
//     f(i, n) cin >> a[i]
// #define iv(v, n)     \
//     vector<ll> v(n); \
//     f(i, n) cin >> v[i]
// #define MOD (1000000007)
// #define INF 1000000000000000000LL // Infinity for ll
// #define mp make_pair
// #define nline '\n'
// #define yes cout << "YES\n"
// #define no cout << "NO\n"

// template <typename T>
// using os = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// template <typename T>
// using oms = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

// // read question properly
// // don't forget newlines!!!!!!
// // take care about cin >> t;
// // comment the optimization before debugging
// // ALWAYS USE FIXED << SETPRECISION WHILE OUTPUTTING FLOATS

// void solve()
// {
//     ll n,m,k;
//     cin >> n >> m >> k;
//     string s[n];
//     f(i,n) {
//         cin >> s[i];
//     }

//     ll pr[n+1][m+1]{};

//     f(i,n) {
//         f(j,m) {
//             pr[i+1][j + 1] = pr[i+1][j] + pr[i][j+1] - pr[i][j] + (s[i][j] == 'g');
//         }
        
//     }

//     ll mi = LLONG_MAX;

//     auto clamp = [&](ll x, ll y) {
//         if(x < 0) x = 0;
//         if(y < 0) y = 0;
//         if(x > n) x = n;
//         if(y > m) y = m;
//         return mp(x,y);
//     };

//     ll cnt = 0;

//     f(i,n) {
//         cnt += count(s[i].begin(), s[i].end(), 'g');
//     }

//     f(i,n) {
//         f(j,m) {
//             if(s[i][j] != '.') continue;

//             //i-k,j-k se i+k,j+k tak ka
//             auto [x1,y1] = clamp(i-k + 1,j-k + 1);
//             auto [x2,y2] = clamp(i + k, j + k);
//             cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<nline;
//             cout<<pr[x2][y2]<<" "<<pr[x2][y1]<<" "<<pr[x1][y2]<<" "<<pr[x1][y1]<<nline;
//             mi = min(mi, pr[x2][y2] - pr[x2][y1] - pr[x1][y2] + pr[x1][y1]);
//         }
//     }

//     cout <<cnt - mi << nline;
// }

// int main()
// {
// #ifdef PRADY
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     clock_t T = clock();
// #endif

//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     long long t = 1;
//     cin >> t;

//     while (t--)
//     {
//         solve();
//     }

// #ifdef PRADY
//     cout << "\nTime taken: " << ((float)(clock() - T)) / CLOCKS_PER_SEC << " seconds";
// #endif
//     return 0;
// }




#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
    ll n,m,k;
    cin >> n >> m >> k;
    string s[n];
    ll cnt=0;
    for (int i = 0; i < n; i++)
    {
        cin>>s[i];
    }

    vector<vector<ll>> pr(n+1,vector<ll>(m+1,0));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(s[i][j]=='g') cnt++;
            pr[i+1][j+1] = (s[i][j]=='g');
            pr[i+1][j+1] += pr[i+1][j];
            pr[i+1][j+1] += pr[i][j+1];
            pr[i+1][j+1] -= pr[i][j];
            //cout<<pr[i+1][j+1]<<" ";
        }
        //cout<<endl;
    }

    ll mi = LLONG_MAX;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(s[i][j]!='.') continue;

            int x1 =max(0LL,i-k+1);
            int y1 = max(0LL,j-k+1);
            int x2 = min(n,i+k);
            int y2 = min(m,j+k);

            mi = min(mi, pr[x2][y2] - pr[x2][y1] - pr[x1][y2] + pr[x1][y1]);

        }
    }
    cout << cnt - mi << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}