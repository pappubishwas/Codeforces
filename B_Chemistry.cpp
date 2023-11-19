#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
    int res = 0, ind = 1, k,n;
    string s;
    cin>>n>>k;
    cin >> s;
    vector<int> ans(26);
    for (int i = 0; i < n; i++)
    {
        ans[s[i]-'a']++;
    }
    
    for (int i = 0; i < 26; i++)
    {
        if(ans[i]%2==1) res++;
    }
    if(res>(k+1)) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}