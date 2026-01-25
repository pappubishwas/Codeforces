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
    int k;
    string s;
    cin>>s;
    int n=s.size();
    int st=(n-1)/2;
    if(n<3){
        cout<<"NO"<<endl;
    }else{
        vector<int> lps(n,0);
        int len=0,i=1;
        while(i<n){
            if(s[len]==s[i]){
                len++;
                lps[i]=len;
                i++;
            }else{
                if(len!=0) len=lps[len-1];
                else i++;
            }
        }
        len=lps[n-1];
        if(len<(n-st)){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
            string ans=s.substr(n-len,len);
            cout<<ans<<endl;
        }
    }
}

int32_t main()
{
    auto begin = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);

    //cin >> t;

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