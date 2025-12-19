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
void Solve()
{
    int n,m;
    cin>>n>>m;
    int px=-1000,py=-1000;
    int p=4LL*m;
    int ans=0;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        if(i==0){
            px=x,py=y;
            ans+=p;
        }else{
            int pex=px+m,pey=py+m;
            int nx=px+x,ny=py+y;
            if((nx>=pex && py>=pey) || nx>pex || ny>pey){
                ans+=p;
            }else{
                int d=abs(pex-nx)+abs(pey-ny);
                ans+=(p-2LL*d);
            }
            px=nx,py=ny;
        }
    }
    cout<<ans<<endl;
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