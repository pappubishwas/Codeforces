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
class DSU
{
public:
    int n;
    vector<int> p, rank;
    DSU(int sz)
    {
        p.assign(sz, 0);
        rank.assign(sz, 0);
        for (int i = 0; i < sz; i++)
            p[i] = i;
    }
    int find(int x)
    {
        if (p[x] == x)
            return x;
        return p[x] = find(p[x]);
    }
    void Unite(int x, int y)
    {
        int px = find(x);
        int py = find(y);
        if (px == py)
            return;
        if (rank[px] < rank[py])
        {
            p[px] = py;
        }
        else if (rank[px] > rank[py])
        {
            p[py] = px;
        }
        else
        {
            p[py] = px;
            rank[px]++;
        }
    }
};
void solve()
{
    int n, a, b;
    cin >> n;
    string s;
    cin >> s;
    int one = 0,zeros=0;
    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            one++;
        }
        if(one>0 && s[i]=='0'){
            flag=false;
        }
        if(s[i]=='0') zeros++;
    }
    if (one == 0 || one==n || flag)
    {
        cout << "Bob" << endl;
    }
    else
    {
        cout << "Alice" << endl;
        vector<int> ans;
        one=0;
        int l=0,r=n-1;
        while(l<=r){
            if(s[l]=='1'){
                ans.push_back(l+1);
                one++;
            }
            if(one>=zeros){
                break;
            }
            if(s[l]=='0')zeros--;
            l++;
        }
        while(l<n){
            if(s[l]=='0'){
                ans.push_back(l+1);
            }
            l++;
        }
        cout<<ans.size()<<endl;
        for(int& t: ans)cout<<t<<" ";
        cout<<endl;
    }
}


// void solve()
// {
//     int n;
//     cin >> n;
//     string s;
//     cin >> s;

//     // 1. Check if already sorted
//     bool is_sorted = true;
//     for (int i = 0; i < n - 1; i++) {
//         if (s[i] > s[i+1]) {
//             is_sorted = false;
//             break;
//         }
//     }

//     if (is_sorted) {
//         cout << "Bob" << endl;
//         return;
//     }

//     int cnt0 = 0;
//     for (char c : s) {
//         if (c == '0') cnt0++;
//     }


//     vector<int> ans;
//     for (int i = 0; i < n; i++) {
//         if (i < cnt0) {

//             if (s[i] == '1') {
//                 ans.push_back(i + 1); 
//             }
//         } else {
//             if (s[i] == '0') {
//                 ans.push_back(i + 1); 
//             }
//         }
//     }

//     cout << "Alice" << endl;
//     cout << ans.size() << endl;
//     for (int i = 0; i < ans.size(); i++) {
//         cout << ans[i] << (i == ans.size() - 1 ? "" : " ");
//     }
//     cout << endl;
// }
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