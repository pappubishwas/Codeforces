#include <bits/stdc++.h>
#include <cstring>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
    int n,t;
    cin >> n;
    set<int> ans;
    map<int,int>mp;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        ans.insert(t);
        mp[t]++;
    }
    if(ans.size()==1) cout<<"Yes"<<endl;
    else if(ans.size()>2) cout<<"No"<<endl;
    else{
        auto it=ans.begin();
        int a=mp[*it],b;
        it++;
        b=mp[*it];
        if(abs(a-b)<=1) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
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