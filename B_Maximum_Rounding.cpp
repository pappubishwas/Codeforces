// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define ld long double
// #define endl '\n'
// void solve()
// {
//     int n;
//     cin >> n;
//     vector<int> v;
//     int i, index;
//     int m = n;
//     while (m > 0)
//     {
//         int temp = m % 10;
//         m = m / 10;
//         v.insert(v.begin(), temp);
//     }
// v.insert(v.begin(), 0);
//     int size = v.size();
//     // index=n;
//     // if(v[0]>=5){
//     //     v.clear();
//     //     v.push_back(1);
//     //     for ( i = 0; i <size; i++)
//     //     {
//     //         v.push_back(0);
//     //     }
//     //     size++;
//     // }else{
//     //     for(i=size-2;i>=0;i-- ){
//     //         if(v[i+1]>=5){
//     //             index=i;
//     //             if(v[i]==9)
//     //                v[i]=0;
//     //             if(i>0)
//     //             v[i-1]++;

//     //         }
//     //     }
//     //     for ( i = index; i < size; i++)
//     //     {
//     //         v[i]=0;
//     //     }

//     // }

// int tp=size;

//     if(v[1]>=5){
//         v.clear();
//         v.push_back(1);
//         for ( i = 1; i <size; i++)
//         {
//             v.push_back(0);
//         }
    
//     }
//     else{
//         /* code */
//         for ( i = 1; i < size; i++)
//         {
//             if(v[i+1]>=5){
                
//                 v[i]=0;
//                 tp=i;
//                 v[i-1]++;
//                 size=i-1;
//                 i=i-2;
                
    
//             }
//         }

//         for ( i = tp; i <v.size(); i++)
//         {
//             v[i]=0;
//         }
    
    
//     }


//     for (i = 1; i < v.size(); i++)
//     {if(v[0]!=0) cout<<v[0];
//         cout << v[i];
//     }
//     cout << endl;
// }
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     ll t;
//     cin >> t;
//     while (t--)
//     {
//         solve();
//     }
//     return 0;
// }











#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> order_set;
mt19937 mt_rand(chrono::high_resolution_clock::now().time_since_epoch().count());
//ld rand(ld a, ld b) {uniform_real_distribution<ld> uni(a, b); return uni(mt_rand);}
//const ld PI=3.141592653589793238462643383279;
const int mxN=1e6+50000;
const int mod=1e9+7;
const int mxlogN=20;
const ll inf=1e18;
const int iinf=2e9;
const int K=450;
int a[mxN];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--)
    {
        string s; cin >> s;
        s="0"+s;
        int n=s.size();
        for(int i=n-1; i; i--)
        {
            if(s[i]>'9')
            {
                s[i-1]++;
                s[i]-=10;
            }
            if(s[i]>='5')
            {
                //cout << "? " << i << "\n";
                s[i-1]++;
                s[i]='x';
            }
        }
        bool ok=0;
        for(int i=0; i<n; i++)
        {
            if(s[i]=='x') ok=1;
            if(ok) s[i]='0';
        }
        if(s[0]=='0') cout << s.substr(1, n-1) << "\n";
        else cout << s << "\n";
    }
}
