#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int t;
    cin >> t;
    while(t--) {
        ll n, c;
        cin >> n ;
        vector<ll> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
       
        ll ct=0,l=0,r=n-1;
        bool flag=true;
        while(l<=r) {
            if(flag){
                if(a[l]>=a[r]){
                    cout<<"L";
                    l++;
                }else{
                    cout<<"R";
                    r--;
                }
                flag=!flag;
            }else{
                if(a[l]>=a[r]){
                    cout<<"R";
                    r--;
                }else{
                    cout<<"L";
                    l++;
                }
                flag=!flag;
            }
        }
        cout<<endl;

    }
    return 0;
}
