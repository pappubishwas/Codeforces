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


void solve() {
    int n, k;
    cin >> n >> k;
    if(n > (int)2e5) {
        cout << "Invalid input";
    }
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    map<int, vector<long long>> mp;
    for(int i=0;i<n;i++) mp[a[i] % k].push_back(a[i]);
    int odd = 0;
    for(pair<int, vector<long long>> p : mp) if(p.second.size() % 2 != 0) odd++;
    if((n % 2 == 0 && odd != 0) || (n % 2 != 0 && odd != 1)) {
        cout << -1 << "\n";
        return;
    }
    long long ans = 0;
    for(pair<int, vector<long long>> p : mp) {
        sort(p.second.begin(), p.second.end());
        if(p.second.size() % 2 == 0) {
            for(int i=0;i<p.second.size();i+=2) ans += (p.second[i + 1] - p.second[i]) / k;
        }
        else {
            map<long long, int> tp;
            for(long long ele : p.second) tp[ele]++;
            vector<long long> test;
            for(pair<long long, int> pp : tp) if(pp.second % 2 != 0) test.push_back(pp.first);
            if(test.size() > 1) {
                if(test.size() % 2 == 0) {
                    for(int i=0;i<test.size();i+=2) ans += (test[i + 1] - test[i]) / k;
                }
                else {
                    vector<long long> aage(test.size(), 0);
                    vector<long long> peeche(test.size(), 0);
                    for(int i=test.size()-2;i>=0;i--) {
                        aage[i] = test[i+1] - test[i];
                        if(i + 2 < test.size()) aage[i] += aage[i + 2];
                    }
                    for(int i=1;i<test.size();i++) {
                        peeche[i] = test[i] - test[i-1];
                        if(i - 2 >= 0) peeche[i] += peeche[i - 2];
                    }
                    //debug(test);
                    //debug(aage);
                    //debug(peeche);
                    long long fans = (int)1e18;
                    for(int i=0;i<test.size();i++) {
                        // if meko ith index nikalni hai
                        long long cans = 0;
                        int ahead_elements = test.size() - i - 1;
                        int behind_elements = i;
                        if(ahead_elements % 2 == 0) {
                            if(i + 1 < test.size()) cans += (aage[i + 1]) / k;
                            if(i - 1 >= 0) cans += (peeche[i - 1]) / k;
                        }
                        else {
                            if(i + 2 < test.size()) cans += (aage[i + 2]) / k;
                            if(i - 2 >= 0) cans += (peeche[i - 2]) / k;
                            if(i + 1 < test.size() && i - 1 >= 0) cans += (test[i+1] - test[i-1]) / k;
                        }
                        fans = min(fans, cans);
                    }
                    ans += fans;
                }
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}