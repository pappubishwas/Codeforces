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

int binaryLength(int n)
{
    return 64 - __builtin_clzll(n);
}

void Solve()
{
    int n,m,x;
    cin>>x>>n>>m;
    int t1=n,t2=m;
    int mn=x,mx=x;
    // while(mn>0 && (n>0 || m>0)){
    //     if(mn==1){
    //         if(n>0) mn=0;
    //         break;
    //     }
    //     if(n>0 && mn%2==1){
    //         mn=mn/2;
    //         n--;
    //     }else if(m>0 && mn%2==0){
    //         mn=mn/2;
    //         m--;
    //     }else if(m>0){
    //         mn=(mn+1)/2;
    //         m--;
    //     }else{
    //         mn=mn/2;
    //         n--;
    //     }
    // }
    // n=t1,m=t2;
    // while(mx>0 && (n>0 || m>0)){
    //     if(mx==1){
    //         if(n>0) mx=0;
    //         break;
    //     }
    //     if(m>0 && mx%2==1){
    //         mx=(mx+1)/2;
    //         m--;
    //     }else if(n>0 && mx%2==0){
    //         mx=mx/2;
    //         n--;
    //     }else if(m>0){
    //         mx=(mx+1)/2;
    //         m--;
    //     }else{
    //         mx=mx/2;
    //         n--;
    //     }
    // }
    
    for(int i=0;i<n && mn>0;i++){
        mn=mn/2;
    }
    for(int i=0;i<m && mn>1;i++){
        mn=(mn+1)/2;
    }
    for(int i=0;i<m && mx>1;i++){
        mx=(mx+1)/2;
    }
    for(int i=0;i<n && mx>0;i++){
        mx=mx/2;
    }
    cout<<mx<<" "<<mn<<endl;
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
        Solve();
    }

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}