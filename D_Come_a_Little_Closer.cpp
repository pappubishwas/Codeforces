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
// const int mod = 998244353;

   
void solve(){
    ll k,res=0,n;
    ll a,b,c,d;
    cin>>n;
    vector<pair<ll,ll>> x(n),y(n);
    for(int i=0;i<n;i++){
        cin>>a>>b;
        x[i].first=a;
        x[i].second=b;
        y[i].first=b;
        y[i].second=a;
    }
    if(n==1){
        cout<<1<<endl;
        return;
    }
    sort(all(x));
    sort(all(y));
    res=LLONG_MAX;
    ll xval,yval;

    // remove smallest x value pair
    xval=x[n-1].first-x[1].first+1;
    yval=((y[n-1].first==x[0].second) ? y[n-2].first : y[n-1].first) - ((y[0].first==x[0].second) ? y[1].first : y[0].first) +1;

    ll rec=xval*yval;
    if(rec==n-1){
        rec+=min(xval,yval);
    }
    res=min(res,rec);

    // remove largest x value pair
    xval=x[n-2].first-x[0].first+1;
    yval=((y[n-1].first==x[n-1].second) ? y[n-2].first : y[n-1].first) - ((y[0].first==x[n-1].second) ? y[1].first : y[0].first) +1;

    rec=xval*yval;
    if(rec==n-1){
        rec+=min(xval,yval);
    }
    res=min(res,rec);

    // remove smallest y value pair
    xval=((y[0].second==x[n-1].first) ? x[n-2].first : x[n-1].first) - ((y[0].second==x[0].first) ? x[1].first : x[0].first)+1;
    yval=y[n-1].first - y[1].first +1;

    rec=xval*yval;
    if(rec==n-1){
        rec+=min(xval,yval);
    }
    res=min(res,rec);

    // remove largest y value pair
    xval=((y[n-1].second==x[n-1].first) ? x[n-2].first : x[n-1].first) - ((y[n-1].second==x[0].first) ? x[1].first : x[0].first) +1;
    yval=y[n-2].first - y[0].first +1;

    rec=xval*yval;
    if(rec==n-1){
        rec+=min(xval,yval);
    }
    res=min(res,rec);



    
    cout<<res<<endl;
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
