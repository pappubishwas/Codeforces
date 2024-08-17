#include<bits/stdc++.h>
using namespace std;

void solve() {
    int start = 0;
    int end = 1000;
    int f = 1000;
    while(end-start>1) {
        int a = (2*start + end) / 3, b=(start+2*end)/3;
        cout << "? " << a << " " << b << endl;
        int ans;
        cin >> ans;
        if(ans == a * b) start = b;
        else if(ans==(a*(b+1))){
            start=a;
            end=b;
        }else
        end=a;
    }
    cout << "! " << end << endl;
}

int main () {
    int t;
    cin >> t;
    while(t-- > 0) solve();
}