#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve() 
{
    int n,k,p,q;
    cin >> n >> k >> p >> q;
    vector<int> pap(n);
    vector<int> remp(n),remq(n);
    vector<int> prefix(n),suffix(n);
    for(int i = 0; i < n; i++) 
    {
        cin >> pap[i];
        remp[i] = pap[i]%p;
        remq[i] = pap[i]%q;
        remq[i]%=p;
        prefix[i]=min(remp[i],remq[i]);
        if(i) prefix[i]+=prefix[i-1];
    }
    suffix[n-1]=min(remp[n-1],remq[n-1]);
    for(int i = n-2; i >= 0; i--) 
    {
        suffix[i]=min(remp[i],remq[i]);
        suffix[i]+=suffix[i+1];
    }
    int sump=accumulate(remp.begin(),remp.begin()+k,0LL);
    int sumq=accumulate(remq.begin(),remq.begin()+k,0LL);
    int ans=min(sump,sumq)+ (k<n ? suffix[k] : 0);
    for(int i = k; i < n; i++){
        sump+=remp[i]-remp[i-k];
        sumq+=remq[i]-remq[i-k];
        ans=min(ans,prefix[i-k]+min(sump,sumq)+ (i+1<n ? suffix[i+1] : 0));
    }
    cout<<ans<<"\n";
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
    for(int i = 1; i <= t; i++) 
    {
        //cout << "Case #" << i << ": ";
        Solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    //cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}