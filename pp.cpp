// Online C++ compiler to run C++ program online

#include<bits/stdc++.h>
using namespace std;
string DFS(int currNode,vector<vector<int>>& adj,vector<bool>& visited){
    visited[currNode]=true;
    string curr=currNode+'A';
    for(int child:adj[currNode]){
        if(visited[child]==false){
            curr+=DFS(child,adj,visited);
        }
    }
    return curr;
}
int main() {
    // Write C++ code here
    vector<string> inp;
    int inpLen;
    cin>> inpLen;
    for(int i=0;i<inpLen;i++){
        cin>>inp[i];
    }
    vector<vector<int>> adj(26);
    for(int i=0;i<inpLen;i++){
        int u=inp[i][0]-'A';
        int v=inp[i][1]-'A';
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> visited(26,false);
    string ans="";
    // for(int i=0;i<26;i++){
    //     if(visited[i]==false){
    //         ans=DFS(0,adj,visited);
    //         if(ans.size()>0) break;
    //     }
    // }
    int start=inp[0][0]-'A';
    ans=DFS(start,adj,visited);
    cout<<ans<<endl;

    return 0;
}