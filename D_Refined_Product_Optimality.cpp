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
const int mod = 998244353;
int rndRange(int l, int r) { return RNG() % (r - l + 1) + l; }

int powerl(int a,int b){
    int res=1;
    while(b){
        if(b&1) res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
int inMod(int a){
    return powerl(a,mod-2);
}
void Solve()
{
    int n,q;
    cin>>n>>q;
    vector<int> a(n),b(n);
    for(auto& t:a) cin>>t;
    for(auto& t:b) cin>>t;
    auto ora=a,orb=b; // keep orginal for update on orginal for the operation
    sort(a.begin(),a.end()); // sort
    sort(b.begin(),b.end()); // sort
    int ans=1;
    for(int i=0;i<n;i++){
        ans=(ans*min(a[i],b[i]))%mod; // before start operation
    }
    cout<<ans<<" ";
    while(q--){
        int o,x;
        cin>>o>>x;
        x--;
        if(o==1){
            int idx=upper_bound(a.begin(),a.end(),ora[x])-a.begin()-1; // we are taking index of before the upper bound 
            ans=(ans*inMod(min(a[idx],b[idx])))%mod; // since idx value will update so we divide the min value that was multiplied on ans
            ora[x]++; // increase in org
            a[idx]++; // increase in sorted array
            ans=(ans*min(a[idx],b[idx]))%mod; // for idx , take the max and update the ans
        }else{
            int idx=upper_bound(b.begin(),b.end(),orb[x])-b.begin()-1;
            ans=(ans*inMod(min(a[idx],b[idx])))%mod;
            orb[x]++;
            b[idx]++;
            ans=(ans*min(a[idx],b[idx]))%mod;
        }
        cout<<ans<<" ";
    }
    cout<<endl;
}

int32_t main()
{
    auto begin = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        Solve();
    }

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    return 0;
}