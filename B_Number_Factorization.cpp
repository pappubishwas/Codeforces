// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define ld long double
// #define endl '\n'
// bool isPrime(ll n)
// {
//     if (n <= 3)
//         return true;

//     if (n % 2 == 0 || n % 3 == 0)
//         return false;

//     for (int i = 5; i * i <= n; i = i + 6)
//         if (n % i == 0 || n % (i + 2) == 0)
//             return false;

//     return true;
// }

// ll nextPrime(ll N)
// {

//     if (N <= 1)
//         return 2;

//     ll prime = N;
//     bool found = false;

//     while (!found)
//     {
//         prime++;

//         if (isPrime(prime))
//             found = true;
//     }

//     return prime;
// }

// void solve()
// {
//     ll n, i = 2, ak = 0, pk = 0;
//     cin >> n;
//     vector<ll> a, p;
//     while (n > 0)
//     {
//         pk = 0;
//         while (n > 0 && n % i == 0)
//         {
//             pk++;
//             n = n / i;
//         }
//         if (pk != 0)
//         {
//             a.push_back(i);
//             p.push_back(pk);
//         }
//         i = nextPrime(i);
//     }

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
using namespace std;

int solve(int n)
{
    if (n == 1)
        return 0;
    int l = 1, m = n;
    for (int i = 2; i * i <= m; i++)
    {
        if (m % i != 0)
            continue;
        while (m % i == 0)
            m /= i;
        l *= i;
    }
    l *= m;
    return l + solve(n / l);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << solve(n) << "\n";
    }
    return 0;
}