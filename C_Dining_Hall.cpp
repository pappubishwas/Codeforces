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

void Solve()
{
    int n, x, r, d, m;
    cin>> n;
    vector<int> pap(n);
    for(int i=0;i<n;i++){
        cin>>pap[i];
    }

    set<vector<int>> pq0,pq1;
    set<pair<int,int>> st;
    auto add=[&](int X,int Y){
        if(st.find({X,Y})!=st.end()){
            return;
        }
        pq0.insert({3*X+3*Y+2,X,Y});

        pq1.insert({3*X+3*Y+2,3*X+1,3*Y+1});
        pq1.insert({3*X+3*Y+3,3*X+1,3*Y+2});
        pq1.insert({3*X+3*Y+3,3*X+2,3*Y+1});
        pq1.insert({3*X+3*Y+6,3*X+2,3*Y+2});
        st.insert({X,Y});
    };

    add(0,0);
    add(0,1);
    add(1,0);

    for(int i=0;i<n;i++){
        if(pap[i]==0){
            auto v=*pq0.begin();
            int x=v[1],y=v[2];
            pq1.erase({3*x+3*y+2,3*x+1,3*y+1});
            pq0.erase(v);
            cout<<3*x+1<<" "<<3*y+1<<endl;

            add(x+1,y);
            add(x+2,y);
            add(x,y+1);
            add(x,y+2);
            add(x+1,y+1);
        }else{
            auto v=*pq1.begin();
            int x=v[1]/3,y=v[2]/3;
            pq1.erase(v);
            pq0.erase({3*x+3*y+2,x,y});
            cout<<v[1]<<" "<<v[2]<<endl;

            add(x+1,y);
            add(x+2,y);
            add(x,y+1);
            add(x,y+2);
            add(x+1,y+1);
        }
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
        Solve();
    }

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}