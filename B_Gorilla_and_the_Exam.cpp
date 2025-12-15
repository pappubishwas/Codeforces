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


int N = 200000;

void Solve()
{
    int n, l, r,y, m,k;
    cin>>n>>k;
    map<int,int> mp;
    for(int i=0;i<n;i++){
        cin>>m;
        mp[m]++;
    }
    priority_queue<int,vector<int>, greater<int>> pq;
    for(auto& it:mp) pq.push(it.second);
    while(k>0 && !pq.empty()){
        int t=pq.top();
        if(k>=t){
            k-=t;
        }else{
            break;
        }
        pq.pop();
    }
    if(pq.size())
    cout<<pq.size()<<endl;
    else cout<<1<<endl;
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