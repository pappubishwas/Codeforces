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
    cin>>n;
    string s;
    cin>>s;
    vector<int> oddCount(26,0),evenCount(26,0);
    for(int i=0;i<n;i++){
        if(i & 1) oddCount[s[i]-'a']++;
        else evenCount[s[i]-'a']++;
    }
    if(n%2==0){
        int mx1=0,mx2=0;
        for(int i=0;i<26;i++){
            mx1=max(mx1,oddCount[i]);
            mx2=max(mx2,evenCount[i]);
        }
        cout<<n-mx1-mx2<<endl;
        return;
    }
    vector<int> prevOdd(26,0),prevEven(26,0);
    int ans=n;
    for(int i=0;i<n;i++){
        if(i&1) oddCount[s[i]-'a']--;
        else evenCount[s[i]-'a']--;
        int mx1=0,mx2=0;
        for(int i=0;i<26;i++){
            mx1=max(mx1,prevEven[i]+oddCount[i]);
            mx2=max(mx2,prevOdd[i]+evenCount[i]);
        }
        ans=min(ans,n-mx1-mx2);
        if(i&1) prevOdd[s[i]-'a']++;
        else prevEven[s[i]-'a']++;
    }
    cout<<ans<<endl;
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