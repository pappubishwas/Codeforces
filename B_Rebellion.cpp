#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;
#define ll long long
#define ld long double
#define endl '\n'
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        int n, i = 0, j, c = 0;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        j = n - 1;
        while (i < j)
        {
            if (arr[j] == 1)
                j--;
            else if (arr[i] == 1 && arr[j] == 0)
            {
                c++;
                i++;
                j--;
            }
            else if (arr[i] == 1 && arr[j] == 1)
            {
                i++;
                j--;
            }
            else if (arr[i] == 0 && arr[j] == 1)
                i++;
            else
                i++;
        }
        cout << c << endl;
    }
    return 0;
}