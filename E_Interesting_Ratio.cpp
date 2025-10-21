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
vector<int> prime;
// void sieve_of_eratosthenes(int n)
// {
//     bool is_prime[n + 1];
//     memset(is_prime, true, sizeof(is_prime));
//     is_prime[0] = is_prime[1] = false;
//     for (int p = 2; p * p <= n; p++) {
//         if (is_prime[p]) {
//             for (int i = p * p; i <= n; i += p) {
//                 is_prime[i] = false;
//             }
//         }
//     }
//     for (int i = 2; i <= n; i++) {
//         if (is_prime[i]) {
//             prime.push_back(i);
//         }
//     }
// }




void normalSieve(int n)
{
    bool isPrime[n / 2];
    memset(isPrime, false, sizeof(isPrime));

    for (int i = 3; i * i < n; i += 2) {
        if (isPrime[i / 2] == false)
            for (int j = i * i; j < n; j += i * 2)
                isPrime[j / 2] = true;
    }

    prime.push_back(2);

    for (int i = 3; i < n; i += 2)
        if (isPrime[i / 2] == false)
            prime.push_back(i);
}


void Solve()
{
    int n,m,k,q,x;
    cin>>n;
    int res=0;
    int p1=prev(upper_bound(prime.begin(),prime.end(),n))-prime.begin();
    for(int i=1;i<=n/2;i++){
        while(1LL*i*prime[p1]>n) p1--;
        res+=p1+1;
    }
    cout<<res<<endl;
}

int32_t main()
{
    auto begin = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);
    // sieve_of_eratosthenes(1000000);
    normalSieve(1e7+1);
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

// const int N = 1e7;
// bool isprime[N + 1];
// vector<int> primes;

// void solve()
// {
//     int n;
//     cin >> n;
//     long long ans = 0;
//     for(int i = 0; i < primes.size() && primes[i] <= n; i++) {
//         ans += n / primes[i];
//     }

//     cout << ans << nline;
// }

// int main()
// {
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     clock_t T = clock();
// #endif

//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     long long t = 1;
//     cin >> t;
//     for (int i = 0; i <= N; i++)
//     {
//         isprime[i] = true;
//     }

//     for (int i = 2; i <= N; i++)
//     {
//         if (isprime[i])
//         {
//             primes.push_back(i);
//             for (int j = 2; i * j <= N; j++)
//             {
//                 isprime[i * j] = false;
//             }
//         }
//     }

//     while (t--)
//     {
//         solve();
//     }

// #ifndef ONLINE_JUDGE
//     cout << "\nTime taken: " << ((float)(clock() - T)) / CLOCKS_PER_SEC << " seconds";
// #endif
//     return 0;
// }
