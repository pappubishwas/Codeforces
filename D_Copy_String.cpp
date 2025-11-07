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
    int n, kmax;
    cin >> n >> kmax;
    string s, t;
    cin >> s >> t;

    if (s == t)
    {
        cout << 0 << "\n";
        return;
    }

    if (s[0] != t[0])
    {
        cout << -1 << "\n";
        return;
    }

    vector<string> results;
    int k = 0;
    // map<char,int> mp;
    // mp[s[0]]=0;
    // for(int i=1;i<n;i++){
    //     if(s[i]!=t[i]){
    //         if(mp.find(t[i])==mp.end()){
    //             cout<<-1<<endl;
    //             return;
    //         }
    //         k=max(i-mp[t[i]],k);
    //         if(k>kmax){
    //             cout<<-1<<endl;
    //             return;
    //         }
    //     }else{
    //         if(mp.find(s[i])==mp.end()){// that's mean this s[i] character appears first so before this element will be not be forward that's clear
    //             mp.clear();
    //         }
    //     }
    //     mp[s[i]]=i;
    // }

    for (int i = n - 1, j = n - 1; i >= 0; i--)
    { // we start checking from the end....
        if (j > i)
            j = i; // if previous element was equal so j did not change , so we move j to the i
        while (j >= 0 && s[j] != t[i])
            j--; // finding the first element in s which is equal to the ith element of target
        if (j < 0)
        {
            cout << -1 << endl; // if that element is not in  s , so no output
            return;
        }
        k = max(k, i - j); // taking the max k , where i-j means the jth char in s will move to ith char in target
    }
    if (k > kmax)
    {
        cout << -1 << endl; // ans possible but needs more than kmax move/operations
        return;
    }
    cout << k << endl;

    // while(k--){
    //     string temps=s;
    //     int j=n-1;
    //     set<char> mp;
    //     while(j>=0){
    //         if(mp.find(temps[j])!=mp.end() && j+1<n){
    //                 temps[j+1]=temps[j];
    //             }
    //         if(temps[j]!=t[j])mp.insert(t[j]);
    //         j--;
    //     }
    //     cout<<temps<<endl;
    //     s=temps;
    // }


    // ans is possible , so finding all the string

    while (s != t)
    {
        for (int i = n - 1, j = n - 1; i > -1; i--)
        {
            if (j > i)
                j = i;
            while (j > -1 && s[j] != t[i])  // finding the first matching of ith char in target to the s  
                j--;
            if (j < i)
            {
                s[j + 1] = s[j]; // there is one match in ith char in target with the jth char in s, it will move one forward
            }
        }

        cout << s << endl;
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
