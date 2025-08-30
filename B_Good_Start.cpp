#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1000000007;
ll add(ll a, ll b, ll m = MOD) { return ((a%m) + (b%m) + m) % m; }
ll sub(ll a, ll b, ll m = MOD) { return ((a%m) - (b%m) + m) % m; }
ll mul(ll a, ll b, ll m = MOD) { return ((a%m) * (b%m)) % m; }
ll modexp(ll a, ll e, ll m = MOD) {
    a %= m; ll r = 1;
    while (e) {
        if (e & 1) r = mul(r, a, m);
        a = mul(a, a, m);
        e >>= 1;
    }
    return r; 
}
ll inv(ll a, ll m = MOD) { return modexp(a, m - 2, m); }

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int tc; cin >> tc;
	while(tc--) {
		ll a, b, k,w,h,x1,x2,y1,y2; cin >>w>>h>> a >> b;
        cin>> x1>>y1>>x2>>y2;
        if(x1>x2){
            swap(x1,x2);
            swap(y1,y2);
        }
        if((y2>=y1 && (y1+b)>y2) || (y2+b>y1 && y2+b<=y1+b)){
            if(abs(x1-x2)%a!=0){
                cout<<"No"<<"\n";
                continue;
            }
        }
        if((x2>=x1 && (x1+a)>x2) || (x2+a>x1 && x2+a<=x1+a)){
            if(abs(y1-y2)%b!=0){
                cout<<"No"<<"\n";
                continue;
            }
        }
        if(abs(x1-x2)%a==0 || abs(y1-y2)%b==0){
            cout<<"Yes"<<"\n";
            
        }else{
            cout<<"No"<<"\n";
        }
 
	}

	return 0;
}