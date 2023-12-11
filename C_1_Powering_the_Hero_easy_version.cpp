#include <bits/stdc++.h>
using namespace std;
#define gcd __gcd
#define ll long long
#define ld long double
#define endl '\n'
#define vvl vector<vll>
#define pll pair<ll, ll>
const int mod = 1e9 + 7;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        ll n, k, ans = 0;
        cin >> n ;
        vector<ll> deck(n); 
        for (size_t i = 0; i < n; i++)
        {
            cin>>deck[i];
        }
        priority_queue<ll> maxHeap;
        for (size_t i = 0; i < n; i++)
        {
            if(deck[i]==0 && !maxHeap.empty()){
                ans+=maxHeap.top();
                maxHeap.pop();
            }else if(deck[i]!=0) maxHeap.push(deck[i]);
        }
        
        cout << ans << endl;
    }
    return 0;
}
