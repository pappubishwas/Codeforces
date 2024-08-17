#include<bits/stdc++.h>
using namespace std;

void solve() {
    int start = 2;
    int end = 999;
    int f = 1000;
    while(start <= end) {
        int mid = (start + end) / 2;
        cout << "? " << mid << " " << mid << endl;
        int ans;
        cin >> ans;
        if(ans == mid * mid) start = mid + 1;
        else {
            f = min(f, mid);
            end = mid - 1;
        }
    }
    cout << "! " << f << endl;
}

int main () {
    int t;
    cin >> t;
    while(t-- > 0) solve();
}