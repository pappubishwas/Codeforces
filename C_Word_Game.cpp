// #include<iostream>
// #include<string>
// using namespace std;
// struct pt
// {
// string word;
// };
// int main()
// {
// int t;
// cin >> t;
// while (t--)
// {
// int n,i,s1=0,s2=0,s3=0;
// cin >> n;
// struct pt p[n],q[n],r[n];
// for ( i = 0; i < n; i++)
// {
//     cin>>p[i].word;
// }
// for ( i = 0; i < n; i++)
// {
//     cin>>q[i].word;
// }
// for ( i = 0; i < n; i++)
// {
//     cin>>r[i].word;
// }

// for ( i = 0; i < n; i++)
// {
//     int c1=0,c2=0,c3=0;
//     for (int j = 0; j < n; j++)
//     {
//         if(p[i].word==q[j].word)
//             c1++;
        
//         if(p[i].word==r[j].word)
//             c1++;
    
//     }

//     if (c1==1)
//         s1=s1+1;
//     else if(c1==0)
//         s1=s1+3;

//     for (int j = 0; j < n; j++)
//     {
//         if(q[i].word==p[j].word)
//             c2++;
        
//         if(q[i].word==r[j].word)
//         c2++;
//     }

//     if (c2==1)
//         s2=s2+1;
//     else if(c2==0)
//         s2=s2+3;   

//     for (int j = 0; j < n; j++){
//         if(r[i].word==p[j].word)
//             c3++;
//         if(r[i].word==q[j].word)
//         c3++;
//     }
//     if (c3==1)
//         s3=s3+1;
//     else if(c3==0)
//         s3=s3+3;        

// }
// cout<<s1<<" "<<s2<<" "<<s3<<endl;
// }
//     return 0;
// }



#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

void solve()
{
    ll a;
    cin >> a;
    unordered_set<string> s1;
    unordered_set<string> s2;
    unordered_set<string> s3;
    for (ll i = 0; i < a; i++)
    {
        string t;
        cin >> t;
        s1.insert(t);
    }
    for (ll i = 0; i < a; i++)
    {
        string t;
        cin >> t;
        s2.insert(t);
    }
    for (ll i = 0; i < a; i++)
    {
        string t;
        cin >> t;
        s3.insert(t);
    }
    ll p1 = 0, p2 = 0, p3 = 0;
    for (auto it : s1)
    {
        if (s2.find(it) == s2.end() && s3.find(it) == s3.end())
            p1 += 3;
        else if (s2.find(it) == s2.end() || s3.find(it) == s3.end())
            p1++;
    }
    for (auto it : s2)
    {
        if (s1.find(it) == s1.end() && s3.find(it) == s3.end())
            p2 += 3;
        else if (s1.find(it) == s1.end() || s3.find(it) == s3.end())
            p2++;
    }
    for (auto it : s3)
    {
        if (s1.find(it) == s1.end() && s2.find(it) == s2.end())
            p3 += 3;
        else if (s1.find(it) == s1.end() || s2.find(it) == s2.end())
            p3++;
    }
    cout << p1 << " " << p2 << " " << p3 << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}



