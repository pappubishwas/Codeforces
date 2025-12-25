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
    int n, q;
    cin >> n >> q;
    vector<int> pap(n),pos(n+1);
    for(int i=0;i<n;i++){
        cin>>pap[i];
        pos[pap[i]]=i+1;
    }
    while(q--){
        int l,r,k;
        cin>>l>>r>>k;
        int posK=pos[k];
        int downOp=0,upOp=0,needSm=0,needGt=0;
        if(posK<l || posK>r){ // the value k is out of the range
            cout<<-1<<" ";
            continue;
        }
        while(true){
            int m=(l+r)/2;
            if(posK==m) break; // m and pos of  k is same
            else if(posK>m && pap[m-1]>k){ // we need to go right but current position of value is greater that we move to left, so need to change the value of current index to smaller value of k
                downOp++;
            }else if(posK<m && pap[m-1]<k){ // we need to go left but curr value is smaller than k that will move to right , so we have chnage with greater value
                upOp++;
            }
            if(posK>m){ // in that pos we need to move to right and here must a smaller value than k
                l=m+1;
                needSm++;
            }else{ // in that pos we need to move left and here must a greater value than k
                r=m-1;
                needGt++;
            }
        }
        if(needSm<k && needGt<=n-k){ // number of value smaller than k is k-1 and number of value greater than k is n-k, it must be satisfied with needs
            cout<<2LL*max(downOp,upOp)<<" "; // in greedy we will take pairs
        }else{
            cout<<-1<<" ";
        }
    }
    cout<<endl;
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