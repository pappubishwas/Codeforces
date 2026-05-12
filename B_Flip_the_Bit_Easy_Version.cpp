#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve()
{
    // int n,k;
    // cin>> n>>k;
    // vector<int> pap(n+1);
    // for(int i=1;i<=n;i++) cin>>pap[i];
    // int idx;
    // cin>>idx;
    // int i=1,j=n;
    // while(i<=n && pap[i]==pap[idx]) i++;
    // while(j>=1 && pap[j]==pap[idx]) j--;
    // if(i>n || j<1){
    //     cout<<0<<endl;
    //     return;
    // }
    // pap[0]=INT_MIN;
    // int ans=0;
    // int count=0;
    // while(i<=idx){
    //     while(i+1<=idx && pap[i]==pap[i+1]) i++;
    //     if(i+1<=idx) count++;
    //     i++;
    // }
    // ans=max(ans,count+1);
    // count=0;
    // while(j>=idx){
    //     while(j-1>=idx && pap[j]==pap[j-1]) j--;
    //     if(j-1>=idx) count++;
    //     j--;
    // }
    // ans=max(ans,count+1);
    // cout<<ans<<endl;

    int n, k;
    cin >> n >> k;
    vector<int> arr(n + 2);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    int pivot;
    cin >> pivot;

    // arr[0] = arr[n+1] = arr[pivot];

    int countL = 0, countR = 0;
    for (int i = 1; i < pivot; i++)
    {
        if (arr[i] != arr[i + 1])
        {
            countL++;
        }
    }
    for (int i = pivot; i < n; i++)
    {
        if (arr[i] != arr[i + 1])
        {
            countR++;
        }
    }
    int value = max(countL, countR);
    if (value % 2)
        value++;
    cout << value << "\n";
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