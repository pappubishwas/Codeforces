 
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll     long long
#define _test   int _TEST; cin>>_TEST; while(_TEST--)
 
int main()
{
    _test
    {
        int n;
        cin>>n;
        
        vector<ll int> a(n);
        for(auto &e: a) cin>>e;
        
        vector<vector<int>> tree(n);
        for(int i=0; i<n-1; i++)
        {
            int u, v;
            cin>>u>>v;
            
            u--, v--;
            
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        
        vector<ll int> cnt(n);
        
        function<void(int, int)> _DFS = [&](int u, int p)
        {
            for(auto v: tree[u])
            {
                if(v == p)      continue;
                
                _DFS(v, u);
                cnt[u] += cnt[v];
            }
            
            cnt[u]++;
        };
        
        _DFS(0, -1);
        
        vector<ll int> val(n);
        
        function<void(int, int)> DFS = [&](int u, int p)
        {
            for(auto v: tree[u])
            {
                if(v == p)      continue;
                
                DFS(v, u);
                
                val[u] += (a[u]^a[v])*1ll*cnt[v] + val[v];
            }
        };
        
        DFS(0, -1);
        
        vector<ll int> ans(n);
        
        function<void(int, int)> DFS2 = [&](int u, int p)
        {
            ans[u] = val[u];
            
            for(auto v: tree[u])
            {
                if(v == p)      continue;
                
                val[u] -= (a[u]^a[v])*1ll*cnt[v];
                val[u] -= val[v];
                cnt[u] -= cnt[v];
                cnt[v] += cnt[u];
                val[v] += (a[u]^a[v])*1ll*cnt[u];
                val[v] += val[u];
                
                DFS2(v, u);
                
                val[v] -= val[u];
                val[v] -= (a[u]^a[v])*1ll*cnt[u];
                cnt[v] -= cnt[u];
                cnt[u] += cnt[v];
                val[u] += val[v];
                val[u] += (a[u]^a[v])*1ll*cnt[v];
            }
        };
        
        DFS2(0, -1);
        
        for(auto e: ans)        cout<<e<<" ";
        cout<<"\n";
    }
}