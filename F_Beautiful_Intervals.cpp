#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve()
{
    int n, k, m,l,r;
    cin>> n>>m;
    vector<bool> start(n+1,false),end(n+1,false);
    l=1,r=n;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        l=max(l,a);
        r=min(r,b);
        start[a]=true;
        end[b]=true;
    }
    if(l<=r){
        int cnt=1;
        for(int i=1;i<=n;i++){
            if(i==l){
                cout<<0<<" ";
            }else{
                cout<<cnt++<<" ";
            }
        }
        cout<<endl;
    }else{
        bool flag=false;
        int pos=0;
        for(int i=1;i<=n;i++){
            if(!start[i] || !end[i]){
                pos=i;
                flag=true;
                break;
            }
        }
        if(flag){
            vector<int> ans(n+1,-1);
            ans[pos]=0;
            if(start[pos] || pos==1){
                ans[pos+1]=1;
            }else{
                ans[pos-1]=1;
            }
            int cnt=2;
            for(int i=1;i<=n;i++){
                if(ans[i]==-1)
                ans[i]=cnt++;
            }
            for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
            cout<<endl;
        }else{
            cout<<"0 2 1 ";
            int cnt=3;
            for(int i=3;i<n;i++)cout<<cnt++<<" ";
            cout<<endl;
        }
    }

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