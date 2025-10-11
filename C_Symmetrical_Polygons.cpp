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

void solve()
{
    ll n, k;
    ll x,y,z;
    cin>>n;
    vector<ll> pap(n);
    map<ll,ll> mp;
    for(auto &x:pap) {
        cin>>x;
        mp[x]++;
    }
    sort(all(pap));
    if(n==3){
        if(pap[0]+pap[1]<=pap[2]){
            cout<<0<<endl;
        }else if(pap[0]==pap[1] || pap[1]==pap[2]){
            cout<<pap[0]+pap[1]+pap[2]<<endl;
        }else{
            cout<<0<<endl;
        }
    }else{
        vector<ll> pq;
        ll res=0;
        ll cnt=0;
        ll mx=0;
        
        for(auto &p:mp){
            res+=(p.first*(p.second-p.second%2));
            cnt+=(p.second - p.second%2);
            if(p.second>=2) mx=max(mx,p.first);
            if(p.second%2) pq.push_back(p.first);
        }
        ll parimeter=0;
        if(cnt>=3 && 2LL*mx<res){
            parimeter=res;
        }
        sort(all(pq));
        for(ll i=0;i<(ll)pq.size();i++){
            ll tmx=max(mx,pq[i]);
            if(cnt+1>=3 && 2LL*tmx<res+pq[i]){
                parimeter=max(parimeter,res+pq[i]);
        }
        }
        for(ll i=0;i<(ll)pq.size()-1;i++){
            ll tmx=max(mx,pq[i]);
            tmx=max(tmx,pq[i+1]);
            if(cnt+2>=3 && 2LL*tmx<res+pq[i]+pq[i+1]){
                parimeter=max(parimeter,res+pq[i]+pq[i+1]);
        }
        }

        cout<<parimeter<<endl;
    }
}


int main()
{  
   IOS;tie;
   int T;
   cin>>T;
   while(T--)
   {
    solve();
   }
    return 0;
}
       




// #include <iostream>
// #include <vector>
// #include <numeric>
// #include <algorithm>
// #include <map>

// // Function to solve a single test case
// void solve() {
//     int n;
//     std::cin >> n;
//     std::map<int, int> counts;
//     for (int i = 0; i < n; ++i) {
//         int a;
//         std::cin >> a;
//         counts[a]++;
//     }

//     long long base_perimeter = 0;
//     long long num_paired_sides = 0;
//     int max_paired_len = 0;
//     std::vector<int> singles;

//     // Separate sticks into pairs and singles
//     for (auto const& [len, count] : counts) {
//         int num_pairs = count / 2;
//         if (num_pairs > 0) {
//             base_perimeter += (long long)num_pairs * 2 * len;
//             num_paired_sides += num_pairs * 2;
//             max_paired_len = std::max(max_paired_len, len);
//         }
//         if (count % 2 == 1) {
//             singles.push_back(len);
//         }
//     }
    
//     // Sort singles in descending order to test longest ones first
//     std::sort(singles.rbegin(), singles.rend());

//     long long max_total_perimeter = 0;

//     // --- Test Case 0: Using only paired sticks ---
//     if (num_paired_sides >= 3 && 2LL * max_paired_len < base_perimeter) {
//         max_total_perimeter = base_perimeter;
//     }
    
//     // --- Test Case 1: Using paired sticks + 1 single stick ---
//     for (int s : singles) {
//         long long p_candidate = base_perimeter + s;
//         int m_candidate = std::max(max_paired_len, s);
//         long long n_candidate = num_paired_sides + 1;
//         if (n_candidate >= 3 && 2LL * m_candidate < p_candidate) {
//             max_total_perimeter = std::max(max_total_perimeter, p_candidate);
//         }
//     }

//     // --- Test Case 2: Using paired sticks + 2 single sticks ---
//     // We only need to test adjacent pairs in the sorted singles list.
//     if (singles.size() >= 2) {
//         for (size_t i = 0; i < singles.size() - 1; ++i) {
//             int s1 = singles[i];
//             int s2 = singles[i+1];
            
//             long long p_candidate = base_perimeter + s1 + s2;
//             int m_candidate = std::max(max_paired_len, s1);
//             long long n_candidate = num_paired_sides + 2;

//             if (n_candidate >= 3 && 2LL * m_candidate < p_candidate) {
//                 max_total_perimeter = std::max(max_total_perimeter, p_candidate);
//             }
//         }
//     }
    
//     std::cout << max_total_perimeter << "\n";
// }

// int main() {
//     // Fast I/O
//     std::ios_base::sync_with_stdio(false);
//     std::cin.tie(NULL);
    
//     int t;
//     std::cin >> t;
//     while (t--) {
//         solve();
//     }
    
//     return 0;
// }