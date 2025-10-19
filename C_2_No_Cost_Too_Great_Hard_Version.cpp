// #include <bits/stdc++.h>
// using namespace std;

// const int MAXVAL = 200002;
// const long long INF = 4e14 + 7;

// int spf[MAXVAL];

// void sieve() {
//     iota(spf, spf + MAXVAL, 0);
//     for (int i = 2; i * i < MAXVAL; ++i) {
//         if (spf[i] == i) {
//             for (int j = i * i; j < MAXVAL; j += i) {
//                 if (spf[j] == j) {
//                     spf[j] = i;
//                 }
//             }
//         }
//     }
// }

// void get_prime_factors(int n, set<int>& factors) {
//     if (n <= 1) return;
//     while (n > 1) {
//         int p = spf[n];
//         factors.insert(p);
//         while (n > 1 && spf[n] == p) {
//             n /= p;
//         }
//     }
// }

// void solve() {
//     int n;
//     cin >> n;
//     vector<int> a(n);
//     vector<long long> b(n);
//     for (int i = 0; i < n; ++i) cin >> a[i];
//     for (int i = 0; i < n; ++i) cin >> b[i];

//     set<int> st;
//     for (int i = 0; i < n; ++i) {
//         get_prime_factors(a[i] - 1, st);
//         get_prime_factors(a[i], st);
//         get_prime_factors(a[i] + 1, st);
//     }

//     long long mnTotalCost = INF;

//     for (int p : st) {
//         long long min1 = INF, min2 = INF;

//         for (int i = 0; i < n; ++i) {
//             long long cost;
//             if (a[i] % p == 0) {
//                 cost = 0;
//             } else {
//                 cost = ((long long)(p - a[i] % p)) * b[i];
//             }

//             if (cost < min1) {
//                 min2 = min1;
//                 min1 = cost;
//             } else if (cost < min2) {
//                 min2 = cost;
//             }
//         }

//         if (min2 != INF) {
//              mnTotalCost = min(mnTotalCost, min1 + min2);
//         }
//     }

//     cout << mnTotalCost << "\n";
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     sieve();

//     int t;
//     cin >> t;
//     while (t--) {
//         solve();
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// const int MAX_A = 200002;
// const long long INF = 4e14 + 7;

// int spf[MAX_A];

// void sieve() {
//     iota(spf, spf + MAX_A, 0);
//     for (int i = 2; i * i < MAX_A; ++i) {
//         if (spf[i] == i) {
//             for (int j = i * i; j < MAX_A; j += i) {
//                 if (spf[j] == j) {
//                     spf[j] = i;
//                 }
//             }
//         }
//     }
// }

// void get_prime_factors(int n, set<int>& factors) {
//     if (n <= 1) return;
//     while (n > 1) {
//         int p = spf[n];
//         factors.insert(p);
//         while (n > 1 && spf[n] == p) {
//             n /= p;
//         }
//     }
// }

// void solve() {
//     int n;
//     cin >> n;
//     vector<int> a(n);
//     vector<long long> b(n);
//     for (int i = 0; i < n; ++i) cin >> a[i];
//     for (int i = 0; i < n; ++i) cin >> b[i];

//     mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//     uniform_int_distribution<int> dist(0, n - 1);

//     const int K = 40;
//     set<int> candidate_primes;

//     for (int k = 0; k < K; ++k) {
//         int i = dist(rng);
//         get_prime_factors(a[i] - 1, candidate_primes);
//         get_prime_factors(a[i], candidate_primes);
//         get_prime_factors(a[i] + 1, candidate_primes);
//     }

//     long long min_total_cost = INF;

//     for (int p : candidate_primes) {
//         long long min1 = INF, min2 = INF;

//         for (int i = 0; i < n; ++i) {
//             long long cost;
//             if (a[i] % p == 0) {
//                 cost = 0;
//             } else {
//                 cost = ((long long)(p - a[i] % p)) * b[i];
//             }

//             if (cost < min1) {
//                 min2 = min1;
//                 min1 = cost;
//             } else if (cost < min2) {
//                 min2 = cost;
//             }
//         }

//         if (min2 != INF) {
//              min_total_cost = min(min_total_cost, min1 + min2);
//         }
//     }

//     cout << min_total_cost << "\n";
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     sieve();

//     int t;
//     cin >> t;
//     while (t--) {
//         solve();
//     }

//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

#define MAXN 200005
vector<int> spf(MAXN + 1, 1);

void sieve()
{

    spf[0] = 0;
    for (int i = 2; i <= MAXN; i++)
    {
        if (spf[i] == 1)
        {
            for (int j = i; j <= MAXN; j += i)
            {
                if (spf[j] == 1)
                    spf[j] = i;
            }
        }
    }
}

set<int> getFactorization(int x)
{
    set<int> ret;
    while (x != 1)
    {
        ret.insert(spf[x]);
        x = x / spf[x];
    }
    return ret;
}

int findZero(int n, vector<int> pap,vector<int> b)
{
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        set<int> t = getFactorization(pap[i]);
        for (auto p : t)
        {
            if (st.find(p) != st.end())
            {
                return 0;
            }
            st.insert(p);
        }
    }
    int res=INF;
    for (int i = 0; i < n; i++)
    {
        set<int> t = getFactorization(pap[i] + 1);
        for (auto p : t)
        {
            if (st.find(p) != st.end())
            {
                res=min(res,b[i]);
            }
        }
    }
    return res;
}

void Solve()
{
    int n, k, m, l, r;
    cin >> n;
    vector<int> pap(n), missing, b(n), one;
    int even = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> pap[i];
        if (pap[i] % 2 == 0)
            even++;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        if (b[i] == 1)
        {
            one.push_back(pap[i]);
        }
    }

    if (even >= 2)
        cout << 0 << endl;
    else
    {
        int ans = findZero(n, pap,b);
        if (ans <=2)
        {
            cout << ans << endl;
            return;
        }
        sort(b.begin(),b.end());

        ans = (one.size() >= 2) ? 2 : ans;
        ans=min(ans,b[0]+b[1]);
        cout << ans << endl;
    }
}

int32_t main()
{
    auto begin = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);
    sieve();
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
