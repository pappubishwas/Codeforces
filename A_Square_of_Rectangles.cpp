#include<bits/stdc++.h>
using namespace std;
bool solve(vector<int> &x) {
   bool case1 = (x[0] == x[2] and x[2] == x[4]) and (x[0] == (x[1] + x[3] + x[5]));
   bool case2 = (x[1] == x[3] and x[3] == x[5]) and (x[1] == (x[0] + x[2] + x[4]));
   bool case3 = (x[0] == (x[2] + x[4]) and x[3] == x[5]) and (x[0] == (x[1] + x[3]));
   bool case4 = (x[1] == (x[3] + x[5]) and x[2] == x[4]) and (x[1] == (x[0] + x[2]));
   return case1 or case2 or case3 or case4;  
}

int main() {
    int t;
    cin >> t;
    while(t--) {
       vector<int> x(6);
       for(int i = 0; i < 6; i++) {
            cin >> x[i];
       }
       cout << (solve(x) ? "YES" : "NO") << "\n";
    }
    return 0;
}