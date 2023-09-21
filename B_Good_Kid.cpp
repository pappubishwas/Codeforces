#include <bits/stdc++.h>
#include<cstring>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
void solve()
{
    int n, arr[9]; // Declare an integer n and an array arr of size 9
    cin >> n; // Read the value of n from input

    // Read n integers into the arr array
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int flag = 0, max1 = 100000;
    long long product = 1;

    // Loop through the elements of the arr array
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0 && flag==0)
            flag = 1;
        else {
            product = product * arr[i];
            if(max1>arr[i])
            max1=arr[i];
        }
    }

    if (flag == 0) {
        product = product / max1;
        product = product * (max1 + 1);
    }

    // Print the result
    cout << product << endl;
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