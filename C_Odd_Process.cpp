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
    int n,x,y,l,k,r,p;
    cin>>n;
    vector<int> odd,even;
    for(int i=0;i<n;i++){
        cin>>p;
        if(p%2) odd.push_back(p);
        else even.push_back(p);
    }
    sort(odd.begin(),odd.end());
    sort(even.begin(),even.end());
    reverse(even.begin(),even.end());
    vector<int> pref(n+1);
    for(int i=0;i<even.size();i++){
        pref[i+1]=even[i]+pref[i];
    }
    for(int i=1;i<=n;i++){
        k=i;
        int need_even=k-1;
        if(need_even<=even.size() && odd.size()>0){
            cout<<pref[need_even]+odd.back()<<" ";
        }else{
            int need_odd=k-1-even.size();
            if(need_odd&1) need_odd++;
            int rem=k-need_odd;
            int sum=0;
            if(rem>0 && need_odd!=odd.size() && odd.size()>0){
                sum+=odd.back();
                rem--;
                sum+=pref[rem];
            }
            cout<<sum<<" ";
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