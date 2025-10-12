#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>

using namespace std;

// const long long INF = 4e18; 
// long long cost3(long long v1, long long v2, long long v3) {
//     long long arr[] = {v1, v2, v3};
//     sort(arr, arr + 3);
//     long long median = arr[1];
//     return abs(v1 - median) + abs(v2 - median) + abs(v3 - median);
// }


// long long solve_linear(const vector<int>& arr) {
//     int m = arr.size();
//     if (m == 0) {
//         return 0;
//     }

//     if (m == 1) {
//         return INF;
//     }

//     vector<long long> dp(m + 1, INF);
//     dp[0] = 0;

//     for (int i = 1; i <= m; ++i) {
//         if (i >= 2) {
//             long long cost2 = abs((long long)arr[i - 1] - arr[i - 2]);
//             if (dp[i - 2] < INF) {
//                 dp[i] = min(dp[i], dp[i - 2] + cost2);
//             }
//         }
//         if (i >= 3) {
//             long long c3 = cost3(arr[i - 3], arr[i - 2], arr[i - 1]);
//             if (dp[i - 3] < INF) {
//                 dp[i] = min(dp[i], dp[i - 3] + c3);
//             }
//         }
//     }
//     return dp[m];
// }

// void solve() {
//     int n;
//     cin >> n;
//     vector<int> a(n);
//     for (int i = 0; i < n; ++i) {
//         cin >> a[i];
//     }


//     long long ans = solve_linear(a);


//     if (n >= 2) {
//         vector<int> sub_arr(a.begin() + 1, a.end() - 1);
//         long long cost_wrap2 = abs((long long)a[n-1] - a[0]);
//         long long res_sub = solve_linear(sub_arr);
//         if (res_sub < INF) {
//             ans = min(ans, cost_wrap2 + res_sub);
//         }
//     }

//     if (n >= 3) {
//         vector<int> sub_arr(a.begin() + 1, a.end() - 2);
//         long long cost_wrap3_left = cost3(a[n-2], a[n-1], a[0]);
//         long long res_sub = solve_linear(sub_arr);
//         if (res_sub < INF) {
//             ans = min(ans, cost_wrap3_left + res_sub);
//         }
//     }
   
//     if (n >= 3) {
//         vector<int> sub_arr(a.begin() + 2, a.end() - 1);
//         long long cost_wrap3_right = cost3(a[n-1], a[0], a[1]);
//         long long res_sub = solve_linear(sub_arr);
//         if (res_sub < INF) {
//             ans = min(ans, cost_wrap3_right + res_sub);
//         }
//     }

//     cout << ans << "\n";
// }

using ll=long long;
#define INF 1000000000000000000LL

ll findAns(vector<ll> pap){
    ll n=pap.size();
    if(n==1) return 0;
    if(n==2) return abs(pap[1]-pap[0]);
    pap.insert(pap.begin(),0LL);
    n++;
    vector<ll> dp(n,INF);
    dp[0]=0;
    dp[2]=abs(pap[2]-pap[1]);
    for(ll i=3;i<n;i++){
        dp[i]=dp[i-2] + abs(pap[i]-pap[i-1]);
        ll mn=LLONG_MAX;
        for(ll j=0;j<3;j++){
            mn=min(mn,abs(pap[i-2+j]-pap[i-2+(j+1)%3])+abs(pap[i-2+j]-pap[i-2+(j+2)%3]));
        }
        dp[i]=min(dp[i],dp[i-3]+mn);
    }
    return dp.back();
}

void solve(){
    ll n;
    cin>>n;
    vector<ll>pap(n);
    for(auto &t:pap) cin>>t;

    ll ans=findAns(pap);
    pap.push_back(pap[0]);
    pap.erase(pap.begin());
    ll t=findAns(pap);

    ans=min(ans,findAns(pap));
    pap.push_back(pap[0]);
    pap.erase(pap.begin());
    ans=min(ans,findAns(pap));
    cout<<ans<<endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}