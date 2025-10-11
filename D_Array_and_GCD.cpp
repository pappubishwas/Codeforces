#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using pbset=tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
template<class T> using pbmultiset=tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update> ;
#define f(i,a,b) for(long long i=a;i<b;i++)
#define rf(i,a,b) for(long long i=a;i>=b;i--)
#define ll long long
#define mp make_pair
#define pb push_back
#define vll vector<long long> 
#define vvl vector<vll>
#define pll pair<ll,ll>
#define vc vector
#define fi first
#define se second
#define lb lower_bound
#define sz(a) (ll)(a.size())
#define remove_unique(x) sort(x.begin(),x.end()); x.erase(unique(x.begin(),x.end()),x.end())
#define to_lowercase(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
#define to_uppercase(s) transform(s.begin(), s.end(), s.begin(), ::toupper)
#define p_q priority_queue
#define pqmax priority_queue<ll>
#define pqmin priority_queue<ll,vector<ll>,greater<ll>>
#define all(x) x.begin(),x.end()
#define inc(x,start) iota(x.begin(),x.end(),start)
#define pi  3.141592653589793238
#define inf  LONG_LONG_MAX
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define IOS ios_base::sync_with_stdio(0)
#define tie cin.tie(NULL),cout.tie(NULL) 
#define endl '\n'
long long POW(long long a,long long b){return (long long)(pow(a,b)+0.5);}
long long gcd(long long a,long long b){return __gcd(a,b);}
long long lcm(long long a,long long b){return (a*b)/__gcd(a,b);}
long long Ceil(long long a,long long b){return (a+b-1)/b;}
long long Sqrt(long long x){ long long y=sqrt(x)+5;while(y*y>x)y--;return y;}
long long sq(long long x){return (1ll*x*x);}
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x) 
#endif
template<class T> void _print(T t){ cerr << t;}
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.fi); cerr << ","; _print(p.se); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> istream& operator>>(istream& in, vector<T> &v){for (auto& i : v) in >> i; return in;}
template <class T> ostream& operator<<(ostream& out, vector<T> &v){for (auto& i : v) out << i << ' '; return out;}
//--------------------------------------------------------------------------------------------------------------------------------------//
const int mod = 1e9 + 7;
const int MOD = 998244353;




std::vector<ll> sieveOfEratosthenes(ll n) {
    // Create the boolean vector to mark numbers
    std::vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;

    // The sieving process (same as before)
    for (ll p = 2; p * p <= n; ++p) {
        if (is_prime[p]) {
            for (ll i = p * p; i <= n; i += p) {
                is_prime[i] = false;
            }
        }
    }

    // Create a vector to store the prime numbers
    std::vector<ll> primes;
    // Collect all prime numbers from the boolean vector
    for (ll p = 2; p <= n; ++p) {
        if (is_prime[p]) {
            primes.push_back(p);
        }
    }
    
    // Return the final vector of primes
    return primes;
}

std::vector<ll> findFirstNPrimes(ll n) {
    if (n <= 0) {
        return {}; // Return an empty vector for non-positive n
    }

    // Step 1: Estimate the upper bound required to find n primes.
    // This formula is a safe upper bound for the n-th prime for n >= 6.
    int limit;
    if (n >= 6) {
        double n_double = static_cast<double>(n);
        limit = static_cast<int>(n_double * (log(n_double) + log(log(n_double))));
    } else {
        // For small n, a fixed small limit is sufficient.
        limit = 15;
    }
    cout<<limit<<endl;
    // Step 2: Run the sieve up to the estimated limit.
    std::vector<ll> all_primes = sieveOfEratosthenes(limit);
    cout<<all_primes.size()<<endl;
    // Step 3: Truncate the vector to contain exactly n primes.
    if (all_primes.size() > n) {
        all_primes.resize(n);
    }
    
    return all_primes;
}

vector<ll> prime;
void solve() {
    ll n,k,m,x,q;
    cin>> n;
    vector<ll> pap(n);
    for(auto &x: pap) cin>> x;
    sort(all(pap));
    ll i=n-1;
    ll p=0;

    ll coin=0;
    while(i>=0){
        if(prime[p]<=pap[i]){
            coin+=(pap[i]-prime[p]);
        }else{
            ll coinNeed=prime[p]-pap[i];
            if(coin>=coinNeed){
                coin-=coinNeed;
            }else{
                break;
            }
        }
        i--;
        p++;
    }
    cout<<i+1<<endl;
}


int main()
{  
   IOS;tie;
   int T;
   cin>>T;
   prime=sieveOfEratosthenes(6000000);
   while(T--)
   {
    solve();
   }
    return 0;
}
