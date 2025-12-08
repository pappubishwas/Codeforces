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

int pow2(int n){ // 2^p, returning in n! , how many 2 factor are there
    int ans=0;
    while(n>0){
        ans+=n/2;
        n/=2;
    }
    return ans;
}

void Solve()
{
    int n,k;
    cin>>n>>k;
    n--;
    for(int i=0;i<=n;i++){
        if(pow2(n)-pow2(n-i)-pow2(i)){ // nCr has factor 2 then it is even, if even then the value will be 0
            cout<<0<<" ";
        }else{ // nCr has not 2 factor
            cout<<k<<" ";
        }
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