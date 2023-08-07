// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long int
// #define endl '\n'
// int findMax(set<int> my_set)
// {

//     int max_element;
//     if (!my_set.empty())
//         max_element = *my_set.rbegin();

//     return max_element;
// }
// int findMin(set<int> my_set)
// {

//     int min_element;
//     if (!my_set.empty())
//         min_element = *(--my_set.rend());

//     return min_element;
// }

// int solve()
// {
//     vector<int> my_set;
//     int n;
//     cin >>n;
//     for (int i = 0; i < n; i++)
//     {
//         int c;
//         cin >> c;
//         my_set.insert(c);
//     }
//     return findMax(my_set) - findMin(my_set);
// }
// int main()
// {
//     ll t;
//     cin >> t;
//     while (t--)
//     {
//         cout << solve() << endl;
//     }
//     return 0;
// }


#include<bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(false);   cin.tie(0);     cout.tie(0);
 
typedef long long ll;
using namespace std;
const int N=2e5+52, M=1e6+6, INF=0x3f3f3f3f;
 
 
 
int main() {
 
FIO
int t;
cin>>t;
 
while(t--){
    int n; cin>>n;
    int a[n];
    for(int i=0; i<n; i++) cin>>a[i];
    int dff = a[n-1] - a[0];
    for(int i=0; i<n-1; i++){
        dff = max(dff, a[i] - a[i+1]);
    }
 
    int f = a[0], l = a[n-1];
    sort(a, a+n);
 
    dff = max(dff, max(l-a[0], a[n-1]-f));
    cout<<dff<<endl;
}
}