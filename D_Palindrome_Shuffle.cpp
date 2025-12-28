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
const int mod = 998244353;
const int MOD = 1e9 + 7;
int rndRange(int l, int r) { return RNG() % (r - l + 1) + l; }
int fact[200001];
int powerl(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
int inMod(int a)
{
    return powerl(a, mod - 2);
}
bool check(string &s,int k){
    int n=s.length();
    multiset<char> left,right;
    for(int i=0;i<k;i++){
        left.insert(s[i]);
        right.insert(s[n-1-i]);
    }
    int l=0,r=n-1;
    while(l<r && r>=k){
        if(s[l]==s[r] && l>=k){
            l++;
            r--;
            continue;
        }
        if(left.find(s[r])==left.end()){
            break;
        }else{
            left.erase(left.find(s[r]));
        }
        l++;
        r--;
    }
    if(l>=r || r<k) return true;
    l=0,r=n-1;
    while(l<r && l<n-k){
        if(s[l]==s[r] && r<n-k){
            l++;
            r--;
            continue;
        }
        if(right.find(s[l])==right.end()){
            break;
        }else{
            right.erase(right.find(s[l]));
        }
        l++;
        r--;
    }
    if(l>=r || l>=n-k) return true;
    return false;
}
void Solve()
{
    int n;
    string s;
    cin>> s;
    n = s.length();
    int l=0,r=n-1;
    while(l<r){
        if(s[l]!=s[r]){
            break;
        }
        l++;
        r--;
    }
    if(l>=r){
        cout<<0<<endl;
        return;
    }
    string  temp=s.substr(l,r-l+1);
    //cout<<temp<<endl;
    l=0,r=temp.length();
    int ans=r+1;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(temp,mid)){
            ans=mid;
            //cout<<ans<<endl;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    cout<<ans<<endl;
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