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
const int mod = 998244353;
const int MOD = 1e9 + 7;
int rndRange(int l, int r) { return RNG() % (r - l + 1) + l; }
int fact[200001];
int powerl(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
int inMod(int a)
{
    return powerl(a, mod - 2);
}
void Solve()
{
    int n, x, y;
    cin >> n >> x >> y;
    string s;
    cin >> s;
    vector<int> pap(n);
    for (int i = 0; i < n; i++)
    {
        cin >> pap[i];
    }
    int total=accumulate(pap.begin(),pap.end(),0LL);
    int amin=0,bmin=0;
    bool flaga=false,flagb=false;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            amin+=(pap[i]/2LL)+1;
            flaga=true;
        }
        else
        {
            bmin+=(pap[i]/2LL)+1;
            flagb=true;
        }
    }
    if(amin>x || bmin>y || (x+y)<total){ // impossible case 
        cout<<"NO"<<endl;
    }else{
        if(flaga && flagb) // both type present
            cout<<"YES"<<endl;
        else if(flaga){ // only a type present
            if(x>=y+n){ // to win a always need min y+n sum, as there are n number of positions
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }else{
            if(y>=x+n){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }    
    }
}
int32_t main()
{
    auto begin = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        Solve();
    }

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    return 0;
}