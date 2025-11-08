
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
    string s;
    cin>>s;
    int c2=0,c3=0,sum=0;
    for(int i=0;i<s.size();i++){
        sum+=(s[i]-'0');
        if(s[i]=='2') c2++;
        if(s[i]=='3') c3++;
    }
    bool flag= sum%9==0;
    sum=sum%9;
    
    for(int i=0;flag==false && i<=min(c2,9LL);i++){
        for(int j=0;j<=min(c3,9LL);j++){
            int tempsum=(sum+i*2+j*6)%9;
            if(tempsum==0){
                flag=true;
                break;
            }
        }
    }
    if(flag){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
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