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

vector<vector<int>> dp(1001); 
vector<int> bestSum(1001,LLONG_MAX);
int N=1000;
int subArray(int n){
    return n*(n-1)/2LL;
}
void preCompute(){
    vector<pair<int,int>> vals;
    dp[0]={};
    bestSum[0]=0;
    for(int len=2;subArray(len)<=N;len++){
        vals.push_back({len,subArray(len)});
    }
    for(int i=1;i<=N;i++){
        for(auto [len,val]:vals){
            if(val<=i && bestSum[i-val]!=LLONG_MAX){
                if(bestSum[i-val]+len<bestSum[i]){
                    bestSum[i]=bestSum[i-val]+len;
                    dp[i]=dp[i-val];
                    dp[i].push_back(len);
                }
            }
        }
    }
}

void Solve()
{
    int n, l,k, r, m;
    cin >> n>>k;
    int x=subArray(n)-k; // number subarray don't have inversion
    if(k==0){
        for(int i=0;i<n;i++) cout<<i+1<<" ";
        cout<<endl;
        return;
    }
    if(x==0){
        for(int i=0;i<n;i++) cout<<n-i<<" ";
        cout<<endl;
        return;
    }
    if(bestSum[x]>n){
        cout<<0<<endl;
        return;
    }
    int currEnd=n, currStart=0;
    for(int i=0;i<dp[x].size();i++){
        currStart=currEnd-dp[x][i]+1;
        for(int j=currStart;j<=currEnd;j++){
            cout<<j<<" ";
        }
        currEnd=currStart-1;
    }
    while (currEnd>0)
    {
        cout<<currEnd<<" ";
        currEnd--;
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
    preCompute();
    for (int i = 1; i <= t; i++)
    {
        Solve();
    }

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    return 0;
}