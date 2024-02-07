
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
//const int mod = 1e9 + 7;
const int mod = 998244353;



void solve() {
	ll n,q;
	cin >> n;
    map<ll,vector<ll>> mp;
    set<ll>s;
    vll pap(n),tan(n+1);
    f(i,0,n){
        cin>>pap[i];
    }
    tan[n-1]=n+2;
    rf(i,n-2,0){
        if(pap[i]==pap[i+1]) tan[i]=tan[i+1];
        else tan[i]=i+1;
    }
    cin>>q;
    f(i,0,q){
        ll l,r;
        cin>>l>>r;
        if(tan[l-1]>r-1) cout<<"-1 -1"<<endl;
        else cout<<l<<" "<<tan[l-1]+1<<endl;
    }
    cout<<endl;
}

int main()
{  
   IOS;tie;
   ll T;
   cin>>T;
   while(T--)
   {
    solve();
   }
    return 0;
}







// class Solution {
// public:
//     int seg[4 * 500015];

//     void build(int idx, int l, int h, vector<int> &a) {
//         if (l == h) {
//             seg[idx] = a[l];
//             return;
//         }
//         int mid = (l + h) / 2;
//         build(2 * idx + 1, l, mid, a);
//         build(2 * idx + 2, mid + 1, h, a);
//         seg[idx] = (seg[2 * idx + 1] & seg[2 * idx + 2]);
//     }

//     int query(int idx, int low, int high, int l, int r) {
//         if (low >= l && high <= r) {
//             return seg[idx];
//         }
//         if (low > r || high < l) return INT_MAX;
//         int mid = (low + high) / 2;
//         int left = query(2 * idx + 1, low, mid, l, r);
//         int right = query(2 * idx + 2, mid + 1, high, l, r);
//         if (left == INT_MAX) return right;
//         if (right == INT_MAX) return left;
//         return (left & right);
//     }

//     vector<int> minQuery(int N, int Q, vector<int> &A, vector<vector<int>> &qu) {
//         build(0, 0, N - 1, A);
//         vector<int> ans;
//         for (int i = 0; i < Q; i++) {
//             int t1 = query(0, 0, N - 1, qu[i][0]-1, qu[i][1]-1);
//             int t2 = query(0, 0, N - 1, qu[i][2]-1, qu[i][3]-1);
//             int t3 = (t1 == INT_MAX || t2 == INT_MAX) ? INT_MAX : (t1 | t2);
//             ans.push_back(t3);
//         }
//         return ans;
//     }
// };






// ll seg[4 * 200015][4];
// void build(ll idx, ll l, ll h, vector<ll> &a) {
//         if (l == h) {
//             seg[idx][0] = a[l];
//             seg[idx][1] = 1;
//             seg[idx][2]=l;
//             seg[idx][3]=l;
//             return;
//         }
//         ll mid = (l + h) / 2;
//         build(2 * idx + 1, l, mid, a);
//         build(2 * idx + 2, mid + 1, h, a);
//         if(seg[2 * idx + 1][0]  != seg[2 * idx + 2][0])
//         {    
//             seg[idx][1] =2 ;
//             seg[idx][2]=seg[2 * idx + 1][2];
//             seg[idx][3]=seg[2 * idx + 2][2];
//         }else{
//             seg[idx][0] = a[l];
//             seg[idx][1] = 1;
//             seg[idx][2]=l;
//             seg[idx][3]=l;
//         }
//     }


//         ll query(ll idx, ll low, ll high, ll l, ll r) {
//         if (low >= l && high <= r) {
//             return seg[idx];
//         }
//         if (low > r || high < l) return ll_MAX;
//         ll mid = (low + high) / 2;
//         ll left = query(2 * idx + 1, low, mid, l, r);
//         ll right = query(2 * idx + 2, mid + 1, high, l, r);
//         if (left == INT_MAX) return right;
//         if (right == INT_MAX) return left;
//         return (left & right);
//     }