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
    int n, l, r,k;
    cin >> n>>k;
    vector<int> p(n);
    map<int, int> mp;
    for (auto &x : p)
    {
        cin >> x;
        mp[x]++;
    }
    int score = 0;
    for(int i=0;i<n;i++){
        if(mp[k-p[i]]>0 && mp[p[i]]>0){
            if(k==2*p[i] && mp[p[i]]>1 )
                score++;
            else if(k!=2*p[i]) score++;    
            mp[k-p[i]]--;
            //cout<<i<<" "; 
        }
        mp[p[i]]--;
    }
    cout<<score<<endl;
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