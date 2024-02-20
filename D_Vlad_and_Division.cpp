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
// void solve(){
//     ll n=0,curr=10;
//     cin>>n;
//     vll tan(n);
//     f(i,0,n){
//         cin>>tan[i];
//     }
//     ll ans=0;
//     f(i,0,31){
//         ll zero=0,one=0;
//         ll mask = 1ll << i;

        
//         f(j, 0, n) {
//             if ((tan[j] & mask) != 0) {
//                 one++;
//             } else {
//                 zero++;
//             }
//         }
//         ll temp=max(zero,one);
//         ans=max(ans,temp);
//     }
//     cout<<ans<<endl;

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
// }



#include <bits/stdc++.h>
#include <stdlib.h>
#include <time.h> 
 
using namespace std;
double EPS = 1e-12;
typedef long long int lld;
typedef pair<lld,lld> PA;
long double tick(){static clock_t oldt; clock_t newt=clock();
    long double diff=1.0L*(newt-oldt)/CLOCKS_PER_SEC; oldt = newt; return diff; }
#define rep(i,a,n) for(long long int i = (a); i <= (n); ++i)
#define repI(i,a,n) for(int i = (a); i <= (n); ++i)
#define repD(i,a,n) for(long long int i = (a); i >= (n); --i)
#define repDI(i,a,n) for(int i = (a); i >= (n); --i)
inline lld sc() { lld a; scanf("%lld", &a); return a; }
inline int scd() { int a; scanf("%d", &a); return a; }
#define prL(a) printf("%lld\n",a)
#define prS(a) printf("%lld ",a)
#define prdL(a) printf("%d\n",a)
#define prdS(a) printf("%d ",a)
#define all(c) (c).begin(), (c).end()
#define sz(a) ((int)a.size())
#ifdef LOCAL_RUN
#define Error(x...) { cout << "(" << #x << ")" << " = ( "; printIt(x); }
#else
#define Error(x...) 42
#endif
template <typename T1> void printIt(T1 t1) { cout << t1 << " )" << endl; }
template <typename T1, typename... T2>
void printIt(T1 t1, T2... t2) { cout << t1 << " , "; printIt(t2...); }
#define popcount __builtin_popcountll

#define lim 300010
#define lim2 200010
// std::ios::sync_with_stdio(false); // Ab :)


lld A[lim];


int main(){
    lld flipper = (1LL << 31) - 1;
    int tt = scd();
    while(tt--) {
        int n = scd();
        multiset<lld> S;
        int ans = n;
        repI(i, 1, n) {
            lld a = sc();
            lld flipped = a ^ flipper;
            Error(a, flipped);
            auto it = S.find(flipped);
            if(it != S.end()) {
                ans--;
                S.erase(it);
            }
            else {
                S.insert(a);
            }
        }
        prdL(ans);
    }
    return 0;
}