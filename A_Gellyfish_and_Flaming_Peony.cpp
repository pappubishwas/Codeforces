// #include<bits/stdc++.h>
// using namespace std;
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template<class T> using pbset=tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
// template<class T> using pbmultiset=tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update> ;
// #define f(i,a,b) for(long long i=a;i<b;i++)
// #define rf(i,a,b) for(long long i=a;i>=b;i--)
// #define ll long long
// #define mp make_pair
// #define pb push_back
// #define vll vector<long long> 
// #define vvl vector<vll>
// #define pll pair<ll,ll>
// #define vc vector
// #define fi first
// #define se second
// #define lb lower_bound
// #define sz(a) (ll)(a.size())
// #define remove_unique(x) sort(x.begin(),x.end()); x.erase(unique(x.begin(),x.end()),x.end())
// #define to_lowercase(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
// #define to_uppercase(s) transform(s.begin(), s.end(), s.begin(), ::toupper)
// #define p_q priority_queue
// #define pqmax priority_queue<ll>
// #define pqmin priority_queue<ll,vector<ll>,greater<ll>>
// #define all(x) x.begin(),x.end()
// #define inc(x,start) iota(x.begin(),x.end(),start)
// #define pi  3.141592653589793238
// #define inf  LONG_LONG_MAX
// #define setbits(x) __builtin_popcountll(x)
// #define zerobits(x) __builtin_ctzll(x)
// #define IOS ios_base::sync_with_stdio(0)
// #define tie cin.tie(NULL),cout.tie(NULL) 
// #define endl '\n'
// long long POW(long long a,long long b){return (long long)(pow(a,b)+0.5);}
// long long gcd(long long a,long long b){return __gcd(a,b);}
// long long lcm(long long a,long long b){return (a*b)/__gcd(a,b);}
// long long Ceil(long long a,long long b){return (a+b-1)/b;}
// long long Sqrt(long long x){ long long y=sqrt(x)+5;while(y*y>x)y--;return y;}
// long long sq(long long x){return (1ll*x*x);}
// #ifndef ONLINE_JUDGE
// #define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
// #else
// #define debug(x) 
// #endif
// template<class T> void _print(T t){ cerr << t;}
// template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.fi); cerr << ","; _print(p.se); cerr << "}";}
// template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T> istream& operator>>(istream& in, vector<T> &v){for (auto& i : v) in >> i; return in;}
// template <class T> ostream& operator<<(ostream& out, vector<T> &v){for (auto& i : v) out << i << ' '; return out;}
// //--------------------------------------------------------------------------------------------------------------------------------------//
// const int mod = 1e9 + 7;
// // const int mod = 998244353;

// // topological sort

// void solve() {
//     ll n;
//     cin >> n;
//     vector<ll> pap(n);
//     for(auto &x:pap) cin>>x;
//     ll g=0;
//     queue<ll> q;
//     ll cnt=0;
//     vector<ll> dp(5001,INT_MAX);
//     for(auto &x:pap){
//         g=__gcd(g,x);
//         q.push(x);
//         dp[x]=0;
//     }
//     for(auto &x:pap){
//         if(x==g) cnt++;
//     }
//     if(cnt>0){
//         cout<<n-cnt<<endl;
//         return;
//     }

//     while(!q.empty() && dp[g]==INT_MAX){
//         ll val=q.front();
//         q.pop();
//         for(auto &x:pap){
//             ll gc=__gcd(val,x);
//             if(dp[gc]==INT_MAX){
//                 dp[gc]=1+dp[val];
//                 q.push(gc);
//             }
//         }
//     }
//     cout<<n+dp[g]-1<<endl;
// }


// int main()
// {  
//    IOS;tie;
//    int T;
//    cin>>T;
//    while(T--)
//    {
//     solve();
//    }
//     return 0;
// }








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

// Function that finds the prime
// factors of a number
vector<int> findPrimeFactors(int n)
{
    // To store the prime factor
    vector<int> primeFactors(9, 0);

    int j = 0;

    // 2s that divide n
    if (n % 2 == 0) {
        primeFactors[j++] = 2;
        while (n % 2 == 0)
            n >>= 1;
    }

    // N must be odd at this point
    // Skip one element
    for (int i = 3;
         i * i <= n; i += 2) {

        if (n % i == 0) {

            // Update the prime factor
            primeFactors[j++] = i;
            while (n % i == 0)
                n /= i;
        }
    }

    // If n is a prime number
    // greater than 2
    if (n > 2)
        primeFactors[j++] = n;
    
    vector<int> PrimeFactors(j);
    
    for(int i = 0; i < j; i++)
    {
        PrimeFactors[i] = primeFactors[i];
    }
    
    return PrimeFactors;
}

// Function that finds the shortest
// subsequence
void findShortestSubsequence(vector<int> &dp, vector<int> a,
                        int index, vector<int> primeFactors)
{
    int n = a.size();

    for (int j = index; j < n; j++) {
        int bitmask = 0;

        for (int p = 0;
             p < primeFactors.size(); p++) {

            // Check if the prime factor
            // of first number, is also
            // the prime factor of the
            // rest numbers in array
            if ((a[j] % primeFactors[p]) == 0) {

                // Set corresponding bit
                // of prime factor to 1,
                // it means both these
                // numbers have the
                // same prime factor
                bitmask ^= (1 << p);
            }
        }

        for (int i = 0; i < dp.size(); i++) {

            // If no states encountered
            // so far continue for this
            // combination of bits
            if (dp[i] == n + 1)
                continue;

            // Update this state with
            // minimum ways to reach
            // this state
            dp[bitmask & i]
                = min(dp[bitmask & i],
                           dp[i] + 1);
        }
    }
}

// Function that print the minimum
// length of subsequence
int printMinimumLength(vector<int> a)
{
    int Min = a.size() + 1;

    for (int i = 0; i < a.size() - 1; i++) {

        // Find the prime factors of
        // the first number
        vector<int> primeFactors
            = findPrimeFactors(a[i]);

        int n = primeFactors.size();
    
        // Initialize the array with
        // maximum steps, size of the
        // array + 1 for instance
        vector<int> dp(1 << n, a.size() + 1);

        // Express the prime factors
        // in bit representation

        // Total number of set bits is
        // equal to the total number
        // of prime factors
        int setBits = (1 << n) - 1;

        // Indicates there is one
        // way to reach the number
        // under consideration
        dp[setBits] = 1;
        findShortestSubsequence(dp, a, i + 1,
                                primeFactors);

        // State 0 corresponds
        // to gcd of 1
        Min = min(dp[0], Min);
    }
    // Else print the length
    return Min;
}

void solve()
{
    ll n;
    cin >> n;
    vector<int> a(n);
    f(i,n) {
        cin >> a[i];
    }
    int g = 0;
    f(i,n) {
        g = __gcd(g,a[i]);
    }
    f(i,n) {
        a[i] /= g;
    }
    ll one=count(a.begin(), a.end(), 1);
    

    if(one > 0) {
        cout << n-one << nline;
        return;
    }
    auto an = printMinimumLength(a);

    cout << n + an - 2 << nline;
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