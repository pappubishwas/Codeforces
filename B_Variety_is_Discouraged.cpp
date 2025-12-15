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

void Solve()
{
    int n, x, y, l, k, r, p;
    cin>>n;
    map<int,int> frq,idx;
    for(int i=0;i<n;i++){
        cin>>x;
        frq[x]++;
        idx[x]=i;
    }
    vector<int> single;
    for(auto& it:frq){
        if(it.second==1){
            single.push_back(idx[it.first]);
        }
    }
    if(single.size()==0) cout<<0<<endl;
    else {
        int window=1,j=0;
        sort(single.begin(),single.end());
        l=single[0]+1; r=single[0]+1;
        n=single.size();
        //cout<<n<<endl;
        for(int i=1;i<single.size();i++){
            if(single[i]!=single[i-1]+1){
                if(window<(i-j)){
                    l=single[j]+1;
                    r=single[i-1]+1;
                    window=i-j;
                }
                j=i;
            }
        }
        if((n-j)>window){
            l=single[j]+1;
            r=single[n-1]+1;
        }
        cout<<l<<" "<<r<<endl;
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