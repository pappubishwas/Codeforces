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
#define pqminp priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>
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

// const ll INF = LLONG_MAX;
// ll dp[25][2][2];

// ll find(int idx, string s, int flag, int n, ll total, int flag2) {
//     if (idx >= n) {
//         return flag == 0 ? INF : total;
//     }

//     if (dp[idx][flag][flag2] != -1) {
//         return dp[idx][flag][flag2];
//     }

//     if (flag) {
//         string temp = s.substr(idx, 1);
//         ll add = find(idx + 1, s, flag, n, total + stoi(temp), 0);
//         ll mull = find(idx + 1, s, flag, n, total * stoi(temp), 1);
//         return dp[idx][flag][flag2] = min(add, mull);
//     } else {
//         string t1 = s.substr(idx, 1);
//         ll oneadd = find(idx + 1, s, 0, n, total + stoi(t1), 0);
//         ll onemull = find(idx + 1, s, 0, n, total * stoi(t1), 1);
//         ll twoadd = INF, twomull = INF;
//         ll res = min(oneadd, onemull);
        
//         if (idx < n - 1) {
//             string t2 = s.substr(idx, 2);
//             twoadd = find(idx + 2, s, 1, n, total + stoi(t2), 0);
//             res = min(res, twoadd);
//             twomull = find(idx + 2, s, 1, n, total * stoi(t2), 1);
//             res = min(res, twomull);
//         }
        
//         return dp[idx][flag][flag2] = res;
//     }
// }

void solve() {
    ll n;
    string s;
    cin >> n;
    cin >> s;
    
    if (n <= 2) {
        cout << stoi(s) << endl;
        return;
    }
    
    // memset(dp, -1, sizeof(dp));
    // string t1 = s.substr(0, 1);
    // string t2 = s.substr(0, 2);
    // ll one = find(1, s, 0, n, stoi(t1), 0);
    // ll two = find(2, s, 1, n, stoi(t2), 0);

    ll res=(1<<20);

    for(int i=0;i+1<n;i++){
        vll tan;

        for(int j=0;j<n;j++){
            if(i==j){
                tan.push_back((s[j]-'0')*10+s[j+1]-'0');
                j++;
            }else{
                tan.push_back(s[j]-'0');
            }
        }
        //debug(tan);
        ll sum=0;
        for(auto x:tan){
            if(x!=1){
                sum+=x;
            }
            if(x==0){
                res=0;
                break;
            }
        }
        if(res==0) break;
        if(sum==0) sum=1;
        res=min(res,sum);
    }
    cout << res << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}