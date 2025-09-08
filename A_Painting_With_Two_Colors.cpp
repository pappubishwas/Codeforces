#include<bits/stdc++.h>
using namespace std;
bool solve(vector<int> &x) {
   if(x[2]>=x[1] && x[2]%2==x[0]%2) return true;
   else if(x[0]%2==x[1]%2 && x[1]%2==x[2]%2) return true;
   else return false;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
       vector<int> x(3);
       for(int i = 0; i < 3; i++) {
            cin >> x[i];
       }
       cout << (solve(x) ? "YES" : "NO") << "\n";
    }
    return 0;
}