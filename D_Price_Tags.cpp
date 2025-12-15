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


int N = 200000;

void Solve()
{
    int n, l, r,y, m;
    cin >> n>>y;
    vector<int> pref(N+1),pap(n);
    for (int i = 0; i < n; i++)
    {
        cin >> pap[i];
        pref[pap[i]]++; // freq count of each cost
    }
    for(int i=1;i<=N;i++) pref[i]+=pref[i-1]; // prefix sum of all freq count
    int ans=-1e18;
    for(int x=2;x<=N;x++){ // brute force on all the x value
        int profit=0;
        for(int i=1;i<=(N+x-1)/x;i++){ // for this x the new value of cost will be on between 1 to ceil(N/x)
            int l=(i-1)*x+1,r=min(i*x,N); // l is till which value it will give cost i , r is the upper value till where it will give cost value i
            int count=pref[r]-pref[l-1]; // count of number that gives new cost value i after devided by x
            profit+=(count*i); // new profit value after devide by x
            int tagNeed=max(0LL,count-(pref[i]-pref[i-1])); // new tag need to print , if the tag is i available on already, we can use those,
            profit-=(tagNeed*y); // total cost to print new tag 
        }
        ans=max(ans,profit);
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