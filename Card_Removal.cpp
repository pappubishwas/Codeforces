#include <bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include <numeric>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
int getMaxRepeatingElement(int array[], int n) 
{
    int i, j, maxElement, count;
     int maxCount = 1;  
    for(i = 0; i< n; i++)  
    {
        count = 1;
        for(j = i+1; j < n; j++) 
        {
            if(array[j] == array[i])
            {
                count++; 
                if(count > maxCount)
                {
                    maxCount = count;
                }
            }
        }
    }
    return maxCount;
}
void solve()
{
int array[100],n;
cin>>n;
for(int i=0;i<n;i++){
    cin>>array[i];
}
int p=getMaxRepeatingElement(array, n);
 cout<<n-p<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

