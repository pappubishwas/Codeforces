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

int rndRange(int l, int r) { return RNG() % (r - l + 1) + l; }

int binaryLength(int n)
{
    return 64 - __builtin_clzll(n);
}
int mod = 998244353;

void solve()
{
    int n,k;
    cin >> n>>k;

    vector<int> p(n);
    for (int i = 0; i < n; ++i)
        cin >> p[i];

    int sum=accumulate(p.begin(),p.end(),0LL);
    int mx=*max_element(p.begin(),p.end());
    for(int sz=n;sz>=1;sz--){
        int need=sum%sz; // using only existing cards ,,, after creating decks with size sz,now extra cards that's will be in another deck
        if(need) need=sz-need;
        if(need>k) continue;
        int total=sum+need;
        int canBuy=k-need; // after remaining coins can used to buy more cards
        int newDeck=canBuy/sz; // using remaining coins how many decks can create
        total+=newDeck*sz; // total card used 
        int totalDeck=total/sz;
        if(totalDeck<mx){
            continue;   // minimum number of deck needs mx, because, one card can once in same deck
        }
        cout<<sz<<endl;
        return;
    }

}

int32_t main()
{
    auto begin = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);

    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}