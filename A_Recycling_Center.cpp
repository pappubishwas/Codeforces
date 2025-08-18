#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int t;
    cin >> t;
    while(t--) {
        ll n, c;
        cin >> n >> c;
        vector<ll> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        ll ct=0;
        for(int i = n-1; i >=0; i--) {
            ll tp=(1<<ct);
            if(tp*a[i] > c) {
                continue;
            }else{
                ct++;
            }
        }
        cout<<n-ct<<endl;
        // if(idx == -1) {
        //     cout << n << endl;
        // } else {
        //     ll ct = 1;
        //     for(int i = idx - 1; i >= 0; i--) {
        //         ll tp = (1LL << ct); 
        //         if(tp * a[i] <= c) {
        //             ct++;
        //         }
        //     }
        //     cout << n - ct << endl;
        // }
    }
    return 0;
}
