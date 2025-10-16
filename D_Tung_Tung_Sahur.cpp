#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve()
{
    int n, k, m,l,r;
    string p,s;
    cin>>p>>s;
    int idp=0,ids=0;
    int cp=0,cs=0;
    n=p.size();
    m=s.size();
    while(idp<n && ids<m){
        char ch=p[idp];
        while(ch==p[idp] && idp<n){
            cp++;
            idp++;
        }
        while(ch==s[ids] && ids<m){
            cs++;
            ids++;
        }
        int mx=2*cp;
        if(cp>cs || cs>mx){
            cout<<"NO"<<endl;
            return;
        }

        cp=0;
        cs=0;
    }
    if(ids<m || idp<n) cout<<"NO"<<endl;
    else
    cout<<"YES"<<endl;
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