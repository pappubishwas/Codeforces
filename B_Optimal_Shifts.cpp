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
    int n,x,y,l,k,r,p;
    cin>>n;
    string s;
    cin>> s;
    int mx=0;
    int i=0;
    while(i<n){
        int j=i;
        while(j<n && s[j]=='0') j++;
        mx=max(mx,j-i);
        i=j+1;
    }
    i=0;
    while(i<n && s[i]=='0') i++;
    int j=n-1;
    while(j>=0 && s[j]=='0') j--;
    mx=max(mx,i+n-j-1LL);
    cout<<mx<<endl;
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