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
const int MOD = 1e9 + 7;
int rndRange(int l, int r) { return RNG() % (r - l + 1) + l; }
int fact[200001];
int powerl(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
int inMod(int a)
{
    return powerl(a, mod - 2);
}


void Solve()
{
    int n, m,x,y,l;
    cin >> n >> m>>l>>x>>y;
    vector<vector<int>> bus(n,vector<int>(2)),people(m,vector<int>(2));
    for(int i=0;i<n;i++){
        cin>> bus[i][0]>>bus[i][1];
    }
    for(int i=0;i<m;i++){
        int p;
        cin>>p;
        people[i][0]=p;
        people[i][1]=i;
    }
    vector<double> ans(m);
    auto com=[&](const auto& a,const auto& b){ // sort by starting and if tighted then sort by ending which one has greater ending
        if(a[0]!=b[0]) return a[0]<b[0];
        return a[1]>b[1];
    };
    sort(bus.begin(),bus.end(),com);
    sort(people.begin(),people.end()); // sort people with there staring position
    double best=INF;
    int j=0;
    for(auto& v:people){
        int p=v[0];
        int idx=v[1];
        while(j<n && bus[j][0]<=p){ // definitely those bus starting position is before current people's  starting position
            int lb=bus[j][0],rb=bus[j][1];
            double ntime=(double)(rb-lb)/(double)x+(double)(l-rb)/(double)y; // for the current people we can use this bus , we calulate total time needs if we take this bus
            best=min(best,ntime); // we will take the best one which will take less time
            j++;
        }
        double walk=(double)(l-p)/(double)y; // we cover whole distance by walk
        ans[idx]=min(walk,best); // take the min one
    }
    for(double t:ans) cout<<setprecision(10)<<t<<endl;
}

int32_t main()
{
    auto begin = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    //cin >> t;

    for (int i = 1; i <= t; i++)
    {
        Solve();
    }

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    return 0;
}