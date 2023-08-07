// #include <bits/stdc++.h>
// #include<iostream>
// #include<algorithm>
// #include <numeric>
// using namespace std;
// #define ll long long
// #define ld long double
// #define endl '\n'
// void solve()
// {
// long long int n,k,i,j=0;
// cin>>n>>k;
// long long int a[n],d[k],sum=0;
// for(i=0;i<n;i++)cin>>a[i];
// if(n==k){
//     for ( j = 0; j < k; j++)
//     {
//         sum=sum+a[j];
//     }
// }else{
//     for(i=0;i<n-k;i++){
//     if(a[i]>a[i+k])d[j]=a[i];
//     else d[j]=a[i+k];
//     j++;

//     if(i==k-1) j=0;
// }
//     if(i==n-k && j!=0){
//         for (int  c = 0; c < n-k; c++)
//         {
//             d[j]=a[i];
//             i++;
//             j++;
//         }
        
//     }
//     for ( j = 0; j < k; j++)
//     {
//         sum=sum+d[j];
//     }
// }
    
// cout<<sum<<endl;

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

#include<bits/stdc++.h>

using namespace std;

int main() {
    long long int t; cin >> t;

    while(t--) {        
        
        long long int n, k; cin >> n >> k;

        vector<long long int> arr(k);

        for(long long int i = 0 ; i < n ; i++) {
            long long int curr; cin >> curr;
            arr[i%k] = max(arr[i%k], curr);
        }

        long long int answer = 0 ;

        for(auto i : arr) answer += i;

        cout << answer << endl;

    }

}
