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

vector<int> lp;
vector<int> pr;
int N = 10000000;

void Solve()
{
    int n, l, r, m;
    cin >> n >> m;
    vector<vector<int>> p(n, vector<int>(m));
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> p[i][j];
        }
        sort(p[i].begin(),p[i].end());
    }
    for(int i=0;i<n;i++){
        int st=p[i][0];
        ans[st]=i+1;
        for(int j=1;j<m;j++){
            if((st+n)!=p[i][j]){
                cout<<-1<<endl;
                return;
            }
            st=p[i][j];
        }
    }
    for(auto& t:ans) cout<<t<<" ";
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