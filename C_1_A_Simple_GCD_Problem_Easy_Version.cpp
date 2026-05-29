#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
int lcm(int a,int b){
    return (a/__gcd(a,b))*b;
}
void Solve() 
{
    int n,k,p,q;
    cin >> n ;
    vector<int> pap(n);
    for(int i=0;i<n;i++){
        cin>>pap[i];
    }
    for(int i=0;i<n;i++){
        cin>>pap[i];
    }
    int ans=(pap[0]!=__gcd(pap[0],pap[1]))+(pap[n-1]!=__gcd(pap[n-1],pap[n-2]));
    for(int i=1;i<n-1;i++){
        if(pap[i]!=lcm(__gcd(pap[i],pap[i-1]),__gcd(pap[i],pap[i+1]))){
            ans++;
        }
    }
    cout<<ans<<endl;
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