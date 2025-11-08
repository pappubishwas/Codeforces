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



// void solve()
// {
//     int n, k;
//     string s;
//     cin>>n;
//     cin>>s;
//     bool isPossible=true,p=false,taken=false;
//     for(int i=0;i<n;i++){
//         if(p && s[i]=='s'){
//             isPossible=false;
//             break;
//         }else if(s[i]=='p'){
//             p=true;
//             if(taken && i+1!=n){
//                 isPossible=false;
//                 break;
//             }
//         }else if(s[i]=='s'){
//             if(i!=0)
//                 taken=true;
//         }
//     }
//     if(isPossible){
//         cout<<"YES"<<endl;
//     }else{
//         cout<<"NO"<<endl;
//     }
// }



void solve()
{
    int n, k;
    string s,t;
    cin>>s>>t;
    map<char,int> mp;
    n=t.size();
    int lens=-1,idxt=-1,l=INT_MAX;
    for(int i=0;i<t.size()-1;i++){
        mp[t[i]]=n-i;
    }
    for(int i=1;i<s.size();i++){
        if(mp.find(s[i])!=mp.end()){
            int len=mp[s[i]]+i;
            if(len<l){
                lens=i;
                idxt=n-mp[s[i]];
                l=len;
            }
        }
    }
    if(idxt==-1) cout<<-1<<endl;
    else{
        cout<<s.substr(0,lens)+t.substr(idxt,n-idxt)<<endl;
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
    t=1;
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