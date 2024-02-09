#include <bits/stdc++.h>
#define int long long int
using namespace std;

int Time = 0;
bool dfs(int node,int src,int p,int dest,vector<vector<int>>&adj,vector<int>&visited,vector<int>&ans)
{
	if(node==dest) return true;

    visited[node]=1;

    for(int el:adj[node]){
        if(el==p) continue;
        if(node== src && el==dest) continue;

        if(visited[el]==0){
            if(dfs(el,src,node,dest,adj,visited,ans)){
                ans.push_back(el);
                return true;
            }
        }
    }
    return false;
}
void dfsBR(int u, int p, vector<vector<int>>& adj, vector<int>& low, vector<int>& disc, set<pair<int,int>>& br) {
    low[u]=disc[u]=++Time;

    for(int v: adj[u]){
        if(v==p) continue;

        if(!disc[v]){
            dfsBR(v,u,adj,low,disc,br);
            low[u]=min(low[u],low[v]);
            if(disc[u]<low[v])
            br.insert({u,v});
        }else{
            low[u]=min(low[u],disc[v]);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<vector<int>> adjj(n + 1);
    vector<pair<int,int>>edges;
    vector<int> cost(m);
    for (int i = 0; i < m; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        adj[a].push_back(b);
        adj[b].push_back(a);
        edges.push_back({a,b});
        cost[i] = d;
    }
    vector<int> low(n + 1), disc(n + 1);
    set<pair<int, int>> br;

    Time = 0;
    for (int u = 1; u <= n; u++)
        if (!disc[u])
            dfsBR(u, u, adj, low, disc, br);
    adj.clear();
    int mina=-1,minb=-1,c = 1e9;
    int ind=0;
    for(auto it:edges)
    {
    	if(br.find({it.first,it.second}) == br.end() && br.find({it.second,it.first}) == br.end())
    	{	adjj[it.first].push_back(it.second);
    		adjj[it.second].push_back(it.first);
    		if(c>cost[ind])
    		{
    			c = cost[ind];
    			mina = it.first;
    			minb = it.second;
    		}
    		
    	}
    	ind++;
    	
    }
    
    cout<<c<<" ";
    vector<int>visited(n+1);
    
    vector<int>ans;
    dfs(mina,mina,mina,minb,adjj,visited,ans);
    ans.push_back(mina);
    cout<<ans.size()<<"\n";
    
    for(int el:ans)
    	cout<<el<<" ";
	cout<<"\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests;
    cin >> tests;
    while (tests--) {
        solve();
    }
    return 0;
}