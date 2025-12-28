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
    int n;
    cin>> n;
    int l=1,r=1,hold=0,ans=2; // intailly both have 1 people and total is 2 and there is no holding
    for(int i=1;i<=n;i++){
        char c1,c2;
        int v1,v2;
        cin>> c1 >> v1 >> c2 >> v2;
        if(c1=='x') v1--; // if c1 is x than mulitple by v1-1 for gain calucation
        if(c2=='x') v2--; // if c2 is x than mulitple by v2-1 for gain calucation
        int side=-1,sp=-1; // side 1 for left ,2 for right ,-1 for none , sp=1 for same values 
        if(c1=='x' && c2=='x'){ // if both are are mutliply by a value
            if(v1>v2){ // if v1 is greater than v2 choose left side, and all gain will be form left
                side=1;
            }else if(v1<v2){ // if v2 is greater than v1 choose right side, and all gain will be form right
                side=2;
            }else{ // we can choose any side as both are same so we will keep it holding that it is not decided so far
                sp=1;
            }
        }else if(c1=='x'){ // only left side is multiply
            side=1;
        }else if (c2=='x') // only right side is multiply
        {
            side=2;
        }
        int inc1,inc2;
        if(c1=='+'){ // if c1 is + than inc1 is v1
            inc1=v1;
        }else{
            inc1=(l+(side==1)*hold+(sp==1)*hold)*v1; // if c1 is x than inc1 is (current people + hold if side is 1 or sp is 1) * v1 , if sp is 1 means v1==v2 , it can go either side
        }
        if(c2=='+'){ // if c2 is + than inc2 is v2
            inc2=v2;
        }else{ // if c2 is x than inc2 is (current people + hold if side is 2) * v2 
            inc2=(r+(side==2)*hold)*v2;
        }
        
        if(side==1){ // if side is 1 add hold to left side
            l+=hold;
        }
        if(side==2){ // if side is 2 add hold to right side
            r+=hold;
        }
        if(side!=-1){ // if side is decided reset hold to 0, for the case v1==v2 it will not enter here and hold can be added to both sides
            hold=0;
        }
        ans+=inc1+inc2; // add inc1 and inc2 to ans
        hold+=inc1+inc2; // add inc1 and inc2 to hold for next iteration, if side is not decided it can be added to both sides
    }
    cout<< ans <<endl;
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