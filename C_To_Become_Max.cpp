#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
double eps = 1e-12;
#define ln "\n"
#define printVector(a) for(int i=0; i<a.size(); i++){cout<<a[i]<<" ";}cout<<ln;
#define print_array(a,n) for(int i=0; i<n; i++){cout<<a[i]<<" ";}cout<<ln;
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define pb push_back
#define take_vector(a) for(auto &x:a)cin>>x;
#define take_array(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define take_matrix(a,m,n) for(int i=0; i<m; i++){for(int j=0; j<n; j++){cin>>a[i][j];}}
#define print_matrix(a,m,n) for(int i=0; i<m; i++){for(int j=0; j<n; j++){cout<<a[i][j]<<" ";}cout<<ln;}
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a/gcd(a,b))*b
#define count(a,x) count(a.begin(), a.end(),x)
#define sum(a) accumulate(a.begin(), a.end(),0)
#define max_ele(a) *max_element(a.begin(), a.end())
#define min_ele(a) *min_element(a.begin(), a.end())

int helper(int i , int x , vector<int> &v ){

    if( v[i] >= x ) return 0;
    else if( i == v.size()-1 and v[i] < x ) return 1e9;
    else{
        return x - v[i] + helper(i+1,x-1,v);
    }

}

bool isPossible(int x , vector<int> &v , int k){

    int n = v.size();

    for(int i = 0 ; i < n ; i++ ){

        int op = helper( i , x , v );

        // dbg(x);
        // dbg(op);

        if( op <= k ) return true;

    }

    return false;

}

int32_t main()
{
  fast_cin();

  int t;
  cin >> t;

  while (t--)
  {

    int n,k;
    cin>>n>>k;

    vector<int> v(n,0);

    for( int i = 0 ; i < n ; i++ ) cin >> v[i];

    int low = max_ele(v);

    int high = low + k;

    int ans = -1;

    while( low <= high ){

        int mid = ( low + high ) / 2;

        if( isPossible(mid,v, k) ){
            ans = mid;
            low = mid+1;
        }
        else high = mid-1;

    }

    cout<<ans<<endl;

  }
  return 0;
}