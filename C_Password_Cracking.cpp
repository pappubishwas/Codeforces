#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define INF (int)1e18
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int rndRange(int l, int r) { return RNG() % (r - l + 1) + l; }

int binaryLength(int n)
{
    return 64 - __builtin_clzll(n);
}
int mod = 998244353;

void solve()
{
    int n,k;
    cin >> n;
    string s="";
    while(s.size()<n){ // this will find the suffix 
        s+="0"; // suffix start with end with zero
        cout<<"? "<<s<<endl; 
        int x;
        cin>>x;
        if(x){
            continue;
        }
        s.pop_back();
        s+="1"; // suffix start with end with one
        cout<<"? "<<s<<endl;
        cin>>x;
        if(x){
            continue;
        }
        s.pop_back(); // there is no additional value , we reached on the end
        break;
    }
    while(s.size()<n){
        s="0"+s; // add the zero start to the suffix
        cout<<"? "<<s<<endl;
        int x;
        cin>>x;
        if(x){ // 1 means correct
            continue;
        }else{ // means there will be one
            s[0]='1';
        }
    }
    cout<<"! "<<s<<endl;
}

int32_t main()
{
    auto begin = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);

    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}