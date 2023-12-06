// #include <bits/stdc++.h>
// #include <cstring>
// using namespace std;
// #define ll int
// #define ld long double
// #define endl '\n'

// vector<int> findDivisors(int n) {
//     vector<int> divisors;
//     for (int i = 1; i * i <= n; i++) {
//         if (n % i == 0) {
//             if (n / i == i) {
//                 divisors.push_back(i);
//             } else {
//                 divisors.push_back(i);
//                 divisors.push_back(n / i);
//             }
//         }
//     }
//     return divisors;
// }

// void solve() {
//     int n, res = 0;
//     cin >> n;
//     vector<int> ans(n);
//     vector<int> mp(100010,0);
//     vector<int>postf(100010,0);

//     for (int i = 0; i < n; i++) {
//         cin >> ans[i];
//         postf[ans[i]]++;
//     }
//     int maxe=ans[0];
//     mp[ans[0]]=1;
//     for (int i = 1; i < n; i++) {
//         vector<int> tem = findDivisors(ans[i]);
//         maxe=max(ans[i],maxe);
//         for (int k = 0; k < tem.size(); k++) {
//             res+=mp[tem[k]];
        
//         }
//         int temp=2*ans[i],p=3;
//         while (temp<=maxe)
//         {
//              res+=mp[temp];
//              temp=temp*p;
//              p++;
//         }
//         mp[ans[i]]++;
//     }
//     cout << res << endl;
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     solve();
//     return 0;
// }



#include <bits/stdc++.h>
using namespace std;
 
const int MIN = 1e5;
const int MAX = 2e5 + 9;
 
long long ans;
int n,a[MAX],cnt[MAX];
 
int main()
{
    cin >> n;
    
    for (int i = 1; i <= n; i ++)
        cin >> a[i],
        cnt[a[i]] ++;
    
    for (int i = 1; i <= MIN; i ++)
    {
        long long now = cnt[i];
        ans += now * (now - 1) / 2;
        
        for (int j = 1; j * j <= i; j ++)
        {
            if (i % j)
                continue;
            
            if (j < i)
                ans += now * cnt[j];
            if (i / j < i && i / j != j)
                ans += now * cnt[i / j];
        }
    }
    
    cout << ans;
    
    return 0;
}
