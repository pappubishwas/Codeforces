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
    int n, k;
    cin >> n >> k;

    vector<int> pap(n);
    for(int i=0;i<n;i++){
        cin>> pap[i];
    }
    auto b=pap;
    sort(b.begin(),b.end());
    deque<int> dq;
    int val=b[k-1]; // we can't remove elements less than val 
    for(int i=0;i<n;i++){
        if(pap[i]<=val) dq.push_back(pap[i]); // we will remove all the elements greater than val
    }
    int cnt=dq.size()-k+1; // number of elements we can remove that are equal to val
    while(dq.size()>1){ // until we have more than 1 element
        if(dq.front() ==dq.back()){ // if both end are equals then they satisfied the palindrome condition
            dq.pop_front();
            dq.pop_back();
        }else{
            if((dq.front()<val && dq.back()<val) || !cnt){  // if both ends are less than val or we can't remove any more elements
                cout<< "NO" << endl;
                return;
            }
            // remove val from one end
            if(dq.front()==val){ 
                dq.pop_front();
            }else{
                dq.pop_back();
            }
            cnt--;
        }
    }
    cout<< "YES" << endl;
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