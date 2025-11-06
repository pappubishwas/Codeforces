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

// pair<int,int> findAns(int l,int r,int k){
//     if(r-l+1<k) return {0LL,0LL};
//     int mid=(l+r)/2;
//     if((r-l+1)%2==0){
//         auto left=findAns(l,mid,k);
//         int total=2LL*left.first+mid*left.second;
//         return {total,2LL*left.second};
//     }else if(l!=r){
//         //cout<<mid<<" ";
//         auto left=findAns(l,mid-1,k);
//         int total=2LL*left.first+mid+mid*left.second;
//         return {total,2LL*left.second+1LL};
//     }
// }


pair<long long,long long> findAns(long long l,long long r,long long k){
    if(r-l+1<k) return {0,0};

    long long mid=(l+r)/2;

    if((r-l+1)%2==0){
        auto left=findAns(l,mid,k);
        __int128 total = (__int128)2*left.first + (__int128)mid*left.second;
        return {(long long)total, left.second*2};
    } else {
        auto left=findAns(l,mid-1,k);
        __int128 total = (__int128)2*left.first + (__int128)mid + (__int128)mid*left.second;
        return {(long long)total, left.second*2 + 1};
    }

    return {0,0}; // Safety return
}


void solve()
{
    int n, m,l,r,k;
    cin >>r>>k;
    auto res=findAns(1,r,k);
    cout<<res.first<<endl;
    
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




// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define INF (int)1e18

// mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

// void Solve() 
// {
//     int n, k; cin >> n >> k;
    
//     auto rec = [&](auto self, int n, int k) -> pair<int, int> {
//         if (n < k) return {0LL, 0LL};
//         // return count and sum 
        
//         pair <int, int> ans = {0, 0};
//         if (n % 2 == 0){
//             auto p1 = self(self, n / 2, k);
//             ans.first += 2 * p1.first;
//             ans.second += 2 * p1.second;
//             ans.second += p1.first * (n / 2);
//         } else {
//             ans.first += 1;
//             ans.second += (n + 1) / 2;
            
//             auto p1 = self(self, n / 2, k);
//             ans.first += 2 * p1.first;
//             ans.second += 2 * p1.second;
//             ans.second += p1.first * ((n + 1) / 2);
//         }
        
//         return ans;
//     };
    
//     auto ans = rec(rec, n, k);
//     cout << ans.second << "\n";
// }

// int32_t main() 
// {
//     auto begin = std::chrono::high_resolution_clock::now();
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     int t = 1;
//     // freopen("in",  "r", stdin);
//     // freopen("out", "w", stdout);
    
//     cin >> t;
//     for(int i = 1; i <= t; i++) 
//     {
//         //cout << "Case #" << i << ": ";
//         Solve();
//     }
//     auto end = std::chrono::high_resolution_clock::now();
//     auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
//     //cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
//     return 0;
// }





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
// int mod = 998244353;

// int findAns(int l,int r,int k){
//     if(r-l+1<k) return 0;
//     int mid=(l+r)/2;
//     if((r-l+1)%2==0){
//         return findAns(l,mid,k)+findAns(mid+1,r,k);
//     }else if(l!=r){
//         cout<<mid<<" ";
//         return mid+findAns(l,mid-1,k)+findAns(mid+1,r,k);
//     }
// }

// void solve()
// {
//     int n, m,l,r;
//     cin >>l>>r;
//     int res=findAns(1,l,r);
//     cout<<res<<endl;
    
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