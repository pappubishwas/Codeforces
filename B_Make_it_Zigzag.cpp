#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve()
{
    int n, k, m,l,r;
    cin>> n;
    vector<int> pap(n),missing;
    int res=0;
    for(int i=0;i<n;i++){
        cin>>pap[i];
    }
    int mx=pap[0];
    for(int i=1;i<n;i+=2){
        mx=max({mx,pap[i-1],pap[i]});
        pap[i]=mx;
    }
    if(n==2){
        if(pap[0]==pap[1]) cout<<1<<endl;
        else cout<<0<<endl;
        return;
    }
    // for(auto p:pap) cout<<p<<" ";
    // cout<<endl;
    // return;
    for(int i=1;i<n-1;i+=2){
        if(pap[i]>pap[i-1] && pap[i]>pap[i+1]){
            continue;
        }
        if(pap[i-1]>=pap[i]){
            res+=abs(pap[i-1]-pap[i])+1;
            pap[i-1]=pap[i]-1;
        }
        if(pap[i+1]>=pap[i]){
            res+=abs(pap[i+1]-pap[i])+1;
            pap[i+1]=pap[i]-1;
        }
    }

    cout<<res<<endl;
}

int32_t main()
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);

    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case #" << i << ": ";
        Solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}












// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define INF (int)1e18
// #define int long long

// void Solve()
// {
//     int n;
//     cin >> n;
//     vector<int> a(n), b(n);
//     int mx = 0;
//     for (int i = 0; i < n; ++i)
//     {
//         cin >> a[i];
//         b[i] = a[i];
//         mx = max(mx, a[i]);
//         if (i % 2 != 0)
//             b[i] = mx;
//     }
//     int res = 0;
//     for (int i = 0; i < n; i += 2)
//     {
//         long long ub = -1;
//         if (i > 0 && i < n - 1)
//             ub = min(b[i - 1], b[i + 1]);
//         else if (i == 0 && n > 1)
//             ub = b[i + 1];
//         else if (i == n - 1 && n > 1)
//             ub = b[i - 1];
//         if (ub != -1 && a[i] >= ub)
//             res += a[i] - (ub - 1);
//     }
//     cout << res << endl;
// }

// int32_t main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int t;
//     cin >> t;
//     while (t--)
//         Solve();
//     return 0;
// }
