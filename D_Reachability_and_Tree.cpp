// #include <bits/stdc++.h>
// using namespace std;

// void dfsout(int x, int p, vector<vector<int>>& adj, bool out) {
//     for(int ch:adj[x]){
//         if(out) cout<< x+1 << " "<<ch+1<<endl;
//         if(ch==p) continue;
//         dfsout(ch,x,adj,!out);
//     }
// }

// int main() {
//     int t;
//     cin >> t;
//     while (t--) {
//         int n;
//         cin >> n;
//         vector<vector<int>> adj(n);
//         for(int i=0;i<n-1;i++){
//                 int x,y;
//                 cin>> x >> y;
//                 adj[x-1].push_back(y-1);
//                 adj[y-1].push_back(x-1);
//             }
//         int d2=-1;
//         for(int i=0;i<n;i++){
//             if(adj[i].size()==2){
//                 d2=i;
//                 break;
//             }
//         }
//         if(d2==-1){
//             cout<<"NO"<<endl;
//             continue;
//         }
//         cout<<"YES"<<endl;
//         cout<<d2+1<<" "<<adj[d2][0]+1<<endl;
//         dfsout(adj[d2][0],d2,adj,false);
//         dfsout(adj[d2][1],d2,adj,true);
        
//     }
//     return 0;
// }



#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
#define INF(t) numeric_limits<t>::max()

void dfsout(int x, int p, vector<vector<int>> &adj, bool out) {
	for(auto y : adj[x]) {
		if(out) cout << x+1 << " " << y+1 << "\n";
		if(y == p) continue;
		dfsout(y, x, adj, !out);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int tc; cin >> tc;
	while(tc--) {
		int n; cin >> n;
		vector<vector<int>> adj(n);
		for(int i = 0; i < n-1; i++) {
			int x, y; cin >> x >> y; x--; y--;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}

		int d2 = -1;
		for(int i = 0; i < n; i++) if(adj[i].size() == 2) { d2 = i; break; }
		if(d2 == -1) { cout << "NO\n"; continue; }
		
		cout << "YES\n";
		cout << d2+1 << " " << adj[d2][0]+1 << "\n";
		dfsout(adj[d2][0], d2, adj, false);
		dfsout(adj[d2][1], d2, adj, true);
	}

	return 0;
}