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


//difference array technique
void solve1()
{
    int n,d,k;
    cin>>n>>d>>k;
    vector<int> diff(2*n+5,0);
    for(int i=0;i<k;i++){
        int l,r;
        cin>>l>>r;
        diff[l]++;
        diff[r+d]--;
    }
    for(int i=1;i<2*n+5;i++){
        diff[i]+=diff[i-1];
    }
    int b=LLONG_MIN,m=LLONG_MAX,ansb=1,ansm=1;
    for(int i=d;i<=n;i++){
        if(b<diff[i]){
            b=diff[i];
            ansb=max(1LL,i-d+1);
        }
        if(m>diff[i]){
            m=diff[i];
            ansm=max(1LL,i-d+1);
        }
    }
    //cout<<diff[5]<<endl;
    cout<<ansb<<" "<<ansm<<endl;
}




// using priority_queue...
void solve(){
    int n,d,k;
    cin>>n>>d>>k;
    vector<pair<int,int>> pap(k);
    for(int i=0;i<k;i++){
        cin>>pap[i].first>>pap[i].second;
    }
    sort(begin(pap),end(pap));
    priority_queue<int,vector<int>,greater<int>> pq;
    int j=0;
    int l=1,r=1,mx=LLONG_MIN,mn=LLONG_MAX;
    for(int i=1;i<=n-d+1;i++){
        while(j<k && pap[j].first<=i+d-1){
            pq.push(pap[j].second);
            j++;
        }
        while(pq.size() && pq.top()<i){
            pq.pop();
        }
        int sz=pq.size();
        if(mx<sz){
            mx=sz;
            l=i;
        }
        if(mn>sz){
            mn=sz;
            r=i;
        }
    }
    cout<<l<<" "<<r<<endl;
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