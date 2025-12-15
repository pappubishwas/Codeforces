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
    int n,x,y,l,r,p;
    cin>>n;
    int sum=(n*(n+1LL))/2LL;
    int sq=sqrtl(sum);
    if(sq*sq==sum){
        cout<<-1<<endl;
        return;
    }
    sum=0;
    int i=1;
    while(i<=n){
        int temp=sum+i;
        int sq=sqrtl(temp);
        if(sq*sq==temp){
            cout<<i+1<<" "<<i<<" ";
            sum+=2LL*i+1;
            i+=2;
        }else{
            cout<<i<<" ";
            sum+=i;
            i+=1;
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