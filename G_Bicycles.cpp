// #include <bits/stdc++.h>
// typedef long long ll;
// typedef long double ld;
// using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
// #define endl '\n'
// #define ilihg ios_base::sync_with_stdio(false);cin.tie(NULL)

// int main() {
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
//     clock_t time_req = clock();
//     ilihg;
//     int t=1;
// 	cin>>t;
// 	while(t--){
// 		int n,m;
// 		cin>>n>>m;
// 		vector<pair<int,int>> node[n+1];
// 		for(int i=0;i<m;i++){
// 		    int a,b,c;
// 		    cin>>a>>b>>c;
// 		    node[a].push_back({b,c});
// 		    node[b].push_back({a,c});
// 		}
// 		int sl[n+1];
// 		for(int i=1;i<=n;i++){
// 			cin>>sl[i];
// 		}
//                         cout<<10<<endl;
// 		vector<vector<ll>> distance(n+1,vector<ll>(1001,1000000000000000000));
// 		distance[1][sl[1]]=0;
// 		set<pair<ll,pair<int,int>>> s;
// 		s.insert({0,{1,sl[1]}});
// 		vector<vector<int>> visited(n+1,vector<int>(1001));
// 		while(s.size()){
// 		    auto currNode=s.begin()->second;
// 		    visited[currNode.first][currNode.second]=1;
// 		    s.erase(s.begin());
// 		    for(auto connectedNode:node[currNode.first]){
// 		    	int minSlow=min(sl[connectedNode.first],currNode.second);
// 		        if(visited[connectedNode.first][minSlow]==0){
// 		            if(s.count({distance[connectedNode.first][minSlow],{connectedNode.first,minSlow}})){
// 		                s.erase({distance[connectedNode.first][minSlow],{connectedNode.first,minSlow}});
// 		            }
// 		            distance[connectedNode.first][minSlow]=min(distance[connectedNode.first][minSlow],distance[currNode.first][currNode.second]+connectedNode.second*currNode.second);
// 		            s.insert({distance[connectedNode.first][minSlow],{connectedNode.first,minSlow}});
// 		        }
// 		    }
// 		}
// 		ll ans=1e18;
// 		for(int i=1;i<=1000;i++){
// 			ans=min(ans,distance[n][i]);
// 		}
// 		cout<<ans<<endl;
// 	}
// #ifndef ONLINE_JUDGE
//     cout << "Time : " << fixed << setprecision(6) << ((double)(clock() - time_req)) / CLOCKS_PER_SEC << endl;
// #endif
// }


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
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

void solve() {

		int n,m;
		cin>>n>>m;
		vector<pair<int,int>> node[n+1];
		for(int i=0;i<m;i++){
		    int a,b,c;
		    cin>>a>>b>>c;
		    node[a].push_back({b,c});
		    node[b].push_back({a,c});
		}
		int sl[n+1];
		for(int i=1;i<=n;i++){
			cin>>sl[i];
		}
		vector<vector<ll>> distance(n+1,vector<ll>(1001,1000000000000000000));
		distance[1][sl[1]]=0;
		set<pair<ll,pair<int,int>>> s;
		s.insert({0,{1,sl[1]}});
		vector<vector<int>> visited(n+1,vector<int>(1001));
		while(s.size()){
		    auto currNode=s.begin()->second;
		    visited[currNode.first][currNode.second]=1;
		    s.erase(s.begin());
		    for(auto connectedNode:node[currNode.first]){
		    	int minSlow=min(sl[connectedNode.first],currNode.second);
		        if(visited[connectedNode.first][minSlow]==0){
		            if(s.count({distance[connectedNode.first][minSlow],{connectedNode.first,minSlow}})){
		                s.erase({distance[connectedNode.first][minSlow],{connectedNode.first,minSlow}});
		            }
		            distance[connectedNode.first][minSlow]=min(distance[connectedNode.first][minSlow],distance[currNode.first][currNode.second]+connectedNode.second*currNode.second);
		            s.insert({distance[connectedNode.first][minSlow],{connectedNode.first,minSlow}});
		        }
		    }
		}
		ll ans=1e18;
		for(int i=1;i<=1000;i++){
			ans=min(ans,distance[n][i]);
		}
		cout<<ans<<endl;
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
