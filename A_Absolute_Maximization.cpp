// #include <bits/stdc++.h>
// #define ll long long
// using namespace std;

// void check(int a[1000],int i,int j){

// }

// int main()
// {
//     ll t;
//     cin >> t;
//     while (t--)
//     {
//         int a[1000], n, max = 0, i, j;
//         cin >> n;
//         for (i = 0; i < n; i++)
//         {
//             cin >> a[i];
//         }
//         for (i = 0; i < n; i++)
//         {
//             for (j = i + 1; j < n; j++)
//             {
//                 check(a,i,j);
//                 if (max > (abs(a[i] - a[j])))
//                     max = abs(a[i] - a[j]);
//             }
//         }
//     }
//     return 0;
// }


#include<stdio.h>
int main()
{
    int a[3][2]={5,1,1,20,25,11};
    int i,j,m,n,o;
    i=++a[1][0];
    j=a[1][0]++;
    m=a[i++][1];
    n=++a[2][2];
    o=a[n--][i--];
    printf("%d %d %d %d %d",i,j,m,n,o);
}



