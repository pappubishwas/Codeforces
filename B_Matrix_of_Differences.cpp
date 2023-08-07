// // ~BhupinderJ
// #include <bits/stdc++.h>
// using namespace std;

// #define endl "\n"
// #define spc <<" "<<
// #define pii pair<int, int>
// #define vvi vector<vector<int>>
// //#define int long long

// const int M = 1e9+7;
// const int N = 1e5+1;

// void SOLVE(){ 
// 	int n; cin >> n;
// 	int hi = n*n, lo = 1;
// 	int t = 0;
// 	vvi ans(n, vector<int>(n));
// 	for(int i=0 ; i<n ; i++){
// 		if(i&1){
// 			for(int j=n-1; j>=0 ; j--){
// 				if(t){
// 					ans[i][j] = hi;
// 					hi--;
// 				}else{
// 					ans[i][j] = lo;
// 					lo++;
// 				}
// 				t^=1;
// 			}
// 		}else{
// 			for(int j=0 ; j<n ; j++){
// 				if(t){
// 					ans[i][j] = hi;
// 					hi--;
// 				}else{
// 					ans[i][j] = lo;
// 					lo++;
// 				}
// 				t^=1;
// 			}
// 		}
// 	}
// 	for(int i=0 ; i<n ; i++){
// 		for(int j=0 ; j<n ; j++)
// 			cout << ans[i][j] << " ";
// 		cout << endl;
// 	}
// }
// signed main(){
// 	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// 	int T = 1; cin >> T;
// 	while(T--) SOLVE();
// }


// ~BhupinderJ
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define spc <<" "<<
#define pii pair<int, int>
#define vvi vector<vector<int>>
//#define int long long

const int M = 1e9+7;
const int N = 1e5+1;

void SOLVE(){ 
	int n; cin >> n;
	int hi = n*n, lo = 1;
	int ans[50][50];
	for(int i=0 ; i<n ; i++){
		if(i%2==1){
			for(int j=n-1; j>=0 ; j--){
				if(j%2==0){
					ans[i][j] = hi;
					hi--;
				}else{
					ans[i][j] = lo;
					lo++;
				}
				
			}
		}else{
			for(int j=0 ; j<n ; j++){
				if(j%2==1){
					ans[i][j] = hi;
					hi--;
				}else{
					ans[i][j] = lo;
					lo++;
				}
			}
		}
	}
	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<n ; j++)
			cout << ans[i][j] << " ";
		cout << endl;
	}
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1; cin >> T;
	while(T--) SOLVE();
}