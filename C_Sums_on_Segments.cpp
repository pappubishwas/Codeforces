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

pair<int,int> maxSubarraySum(vector<int> &arr,int s,int n)
{
    if (s>n)
    {
        return {0LL,0LL};
    }
 
    int mx = arr[s];
    int mn = arr[s];
    int maxEnding = arr[s];
    int minEnding = arr[s];
 
    for (int i = s+1; i <=n; i++)
    {
 
        // Find the maximum sum ending at index i by either extending
        // the maximum sum subarray ending at index i - 1 or by
        // starting a new subarray from index i
        maxEnding = max(maxEnding + arr[i], arr[i]);
        minEnding = min(minEnding + arr[i], arr[i]);
 
        // Update res if maximum subarray sum ending at index i > res
        mx = max(mx, maxEnding);
        mn=min(mn,minEnding);
    }
    return {min(0LL,mn),max(mx, 0LL)};
}
 

void solve()
{
    int n,idx=-1;
    cin>> n;
    vector<int> pap(n);
    for(int i=0;i<n;i++) {
        cin>> pap[i];
        if(pap[i]!=-1 && pap[i]!=1){
            idx=i;
        }
    }
    set<int> ans;
    if(idx==-1){
        pair<int,int> p=maxSubarraySum(pap,0,n-1);
        for(int s=p.first;s<=p.second;s++){
            ans.insert(s);
        }
    }else{
        pair<int,int> p1=maxSubarraySum(pap,0,idx-1);
        pair<int,int> p2=maxSubarraySum(pap,idx+1,n-1);
        
        for(int s=p1.first;s<=p1.second;s++){
            ans.insert(s);
        }
        for(int s=p2.first;s<=p2.second;s++){
            ans.insert(s);
        }
        ans.insert(pap[idx]);
        int sum=0;
        set<int> left,right;
        left.insert(0);
        right.insert(0);
        for(int s=idx+1;s<n;s++){
            sum+=pap[s];
            right.insert(sum);
        }
        sum=0;
        for(int s=idx-1;s>=0;s--){
            sum+=pap[s];
            left.insert(sum);
        }
        int l=pap[idx]+*left.begin()+*right.begin();
        int r=pap[idx]+*left.rbegin()+*right.rbegin();
        for(int i=l ;i<=r;i++){
            ans.insert(i);
        }
    }
    cout<<ans.size()<<endl;
    for(auto t:ans) cout<<t<<" ";
    cout<<endl;

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
    // t=1;
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