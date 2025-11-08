
// #include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace std;
// using namespace __gnu_pbds;
// #define int long long
// #define INF (int)1e18
// mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
// template <class T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// int rndRange(int l, int r) { return RNG() % (r - l + 1) + l; }

// int binaryLength(int n)
// {
//     return 64 - __builtin_clzll(n);
// }
// int mod = 998244353;

// map<pair<int,int>,int> mp;
// bool check(int i,int sum,string& s){

//     if(i==s.size()) return sum%9LL==0LL;

//     bool  result=false;
//     if(mp.find({i,sum})!=mp.end()) return mp[{i,sum}];
//     if(s[i]<='3'){
//         int t=s[i]-'0';
//         result= check(i+1,(sum+t*t)%9LL,s) || check(i+1,(sum+t)%9LL,s);
//     }else{
//         result=check(i+1,(sum+(s[i]-'0'))%9LL,s);
//     }
//     return mp[{i,sum}]=result;
// }

// void solve()
// {
//     int n, k;
//     string s;
//     cin>>s;
//     if(check(0,0LL,s)){
//         cout<<"YES"<<endl;
//     }else{
//         cout<<"NO"<<endl;
//     }
// }

// int32_t main()
// {
//     auto begin = chrono::high_resolution_clock::now();
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     int t = 1;
//     // freopen("in",  "r", stdin);
//     // freopen("out", "w", stdout);

//     cin >> t;
//     for (int i = 1; i <= t; i++)
//     {
//         // cout << "Case #" << i << ": ";
//         mp.clear();
//         solve();
//     }

//     auto end = chrono::high_resolution_clock::now();
//     auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
//     // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
//     return 0;
// }





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
    cin>>n;
    vector<pair<int,int>> mat(n);
    for(int i=0;i<n;i++){
        cin>>mat[i].first;
    }
    for(int i=0;i<n;i++){
        cin>>mat[i].second;
    }

    // auto comp=[&](auto& a,auto& b){
    //     return a.second<b.second;
    // };

    // sort(begin(mat),end(mat),comp);

    int ma=0,mb=0,idx=0;
    int ans=INT_MIN;
    int sum=INT_MIN,upsum=0,besum=0;
    for(int i=0;i<n;i++){
        if(mat[i].first-mat[i].second<0){
            besum+=mat[i].second;
        }else{
            upsum+=mat[i].first;
        }
        if(min(mat[i].first,mat[i].second)>sum){
            idx=i;
            sum=min(mat[i].first,mat[i].second);
        }
    }
    cout<<sum+besum+upsum<<endl;


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