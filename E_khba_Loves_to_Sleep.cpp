// #include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace std;
// using namespace __gnu_pbds;
// #define int long long
// #define INF (int)1e18
// mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
// template <class T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// int rndRange(int l, int r) { return RNG() % (r - l + 1) + l; }

// int binaryLength(int n)
// {
//     return 64 - __builtin_clzll(n);
// }
// int mod=998244353;
// int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};

// bool check(int mindiff,vector<long long> &a,int n,int k,int x){
//     int count=max(0LL,a[0]-mindiff+1);
//     count+=max(0LL,x-a[n-1]-mindiff+1);
//     for(int i=0;i<n-1;i++){
//         int right=a[i]+mindiff;
//         int left=a[i+1]-mindiff;
//         if(left>=right){
//             count+=(left-right+1);
//         }
//     }
//     return count>=k;
// }

// void solve() {
//     int n,k,x;
//     cin >> n>>k>>x;
//     vector<long long> a(n+2);
//     vector<int> ans(k);
//     for (int i = 0; i < n; ++i) {
//         cin >> a[i];
//     }
//     sort(a.begin(),a.end());
//     int mxdiff=(x+1)-k-n;
//     if(mxdiff<0){
//         for(int i=0;i<k;i++) cout<<i<<" ";
//         cout<<"\n";
//     }else if(mxdiff==0){
//         int start=0;
//         for(int i=0;i<n;i++){
//             if(a[i]==start){
//                 start++;
//             }else{
//                 cout<<start<<" ";
//                 start++;
//                 k--;
//             }
//         }
//         while(k>0){
//             cout<<start<<" ";
//             start++;
//             k--;
//         }
//         cout<<"\n";
//     }
//     else{
//         int minDiff=0;
//         int diff=0;
//         while(minDiff<=mxdiff){
//             int mid=(minDiff+mxdiff)/2;
//             if(check(mid,a,n,k,x)){
//                 diff=mid;
//                 minDiff=mid+1;
//             }else{
//                 mxdiff=mid-1;
//             }
//         }
//         //cout<<"Diff: "<<diff<<"\n";
//         int currx=0;
//         int i=0;
//         while(k>0 && currx+diff<=a[0]){
//             ans[i]=currx;
//             currx++;
//             i++;
//             k--;
//         }
//         int t=0;
//         while(k>0 && t+1<n){
//             int right=a[t]+diff;
//             int left=a[t+1]-diff;
//             int el=left - right +1;
//             while (el>0)
//             {
//                 ans[i]=right;
//                 right++;
//                 i++;
//                 k--;
//                 el--;
//                 if(k==0) break;
//             }
//             t++;
//         }
//         currx=a[n-1]+diff;
//         while(k>0 && currx<=x){
//             ans[i]=currx;
//             currx++;
//             i++;
//             k--;
//         }
//         for(auto val:ans) cout<<val<<" ";
//         cout<<"\n";
//     }

// }

// int32_t main()
// {
//     auto begin = chrono::high_resolution_clock::now();
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     int t = 1;
//     // freopen("in",  "r", stdin);
//     // freopen("out", "w", stdout);

//     cin >> t;
//     for (int i = 1; i <= t; i++)
//     {
//         // cout << "Case #" << i << ": ";
//         solve();
//     }

//     auto end = chrono::high_resolution_clock::now();
//     auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
//     // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
//     return 0;
// }





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
int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};

bool check(int mindiff, vector<long long> &a, int n, int k, int x)
{
    int count = max(0LL, a[0] - mindiff + 1);
    count += max(0LL, x - (a[n - 1] + mindiff) + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int right = a[i] + mindiff;
        int left = a[i + 1] - mindiff;
        if (left >= right)
        {
            count += (left - right + 1);
        }
    }
    return count >= k;
}

void solve()
{
    int n, k, x;
    cin >> n >> k >> x;

    vector<long long> a(n);
    vector<int> ans(k); 
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end()); 

    int minDiff = 0;
    int mxdiff = x;
    int diff = 0; 

    while (minDiff <= mxdiff)
    {
       
        int mid = minDiff + (mxdiff - minDiff) / 2;
        if (check(mid, a, n, k, x))
        {
            diff = mid;
            minDiff = mid + 1;
        }
        else
        {
            mxdiff = mid - 1;
        }
    }

   
    int i = 0;             
    int currval = 0; 
    int end = a[0] - diff;
    while (k > 0 && currval <= end)
    {
        ans[i++] = currval++;
        k--;
    }

    for (int t = 0; t < n - 1 && k > 0; t++)
    {
        int start = a[t] + diff;
        int end = a[t + 1] - diff;

        currval = max(currval, start);

        while (k > 0 && currval <= end)
        {
            ans[i++] = currval++;
            k--;
        }
    }

    int newstart = a[n - 1] + diff;
    currval = max(currval, newstart);

    while (k > 0 && currval <= x)
    {
        ans[i++] = currval++;
        k--;
    }
    for (auto val : ans)
        cout << val << " ";
    cout << "\n";
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
