#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define INF (int)1e18
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int rndRange(int l, int r) { return RNG() % (r - l + 1) + l; }

int binaryLength(int n)
{
    return 64 - __builtin_clzll(n);
}
int p = 998244353;

const int N = 200005;

// array to store inverse of 1 to N
int factorialNumInverse[N + 1];

// array to precompute inverse of 1! to N!
int naturalNumInverse[N + 1];

// array to store factorial of first N numbers
int fact[N + 1];

// Function to precompute inverse of numbers
void InverseofNumber(int p)
{
    naturalNumInverse[0] = naturalNumInverse[1] = 1;
    for (int i = 2; i <= N; i++)
        naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p;
}
// Function to precompute inverse of factorials
void InverseofFactorial(int p)
{
    factorialNumInverse[0] = factorialNumInverse[1] = 1;

    // precompute inverse of natural numbers
    for (int i = 2; i <= N; i++)
        factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p;
}

// Function to calculate factorial of 1 to N
void factorial(int p)
{
    fact[0] = 1;

    // precompute factorials
    for (int i = 1; i <= N; i++) {
        fact[i] = (fact[i - 1] * i) % p;
    }
}

// Function to return nCr % p in O(1) time
int Binomial(int N, int R, int p)
{
    // n C r = n!*inverse(r!)*inverse((n-r)!)
    int ans = ((fact[N] * factorialNumInverse[R])
              % p * factorialNumInverse[N - R])
             % p;
    return ans;
}

int combination(int n){
    int res=0;
    for(int i=1;i<=n;i++){
        res+=Binomial(n,i,p)%p;
        res%=p;
    }
    return res;
}

// void solve()
// {
//     int n,k;
//     cin>>n;
//     vector<int> pap(n),prefixTwoCount(n+1),oneidx;
//     for(int i=0;i<n;i++){
//         cin>>pap[i];
//         prefixTwoCount[i+1]=prefixTwoCount[i];
//         if(pap[i]==2) prefixTwoCount[i+1]++;
//         if(pap[i]==1) oneidx.push_back(i);
//     }
//     int res=0;
//     for(int i=0;i<n;i++){
//         if(pap[i]==3){
//             int idx=0;
//             while(idx<oneidx.size() && oneidx[idx]<i){
//                 int two=prefixTwoCount[i+1]-prefixTwoCount[oneidx[idx]];
//                 if(two>0){
//                     //cout<<two<<" ";
//                     res+=combination(two)%p;
//                     res%=p;
//                 }
//                 idx++;
//             }
//         }
//     }
//     cout<<res<<endl;
// }




void solve()
{
    int n;
    cin >> n;
    vector<int> pap(n);
    for (int i = 0; i < n; i++) {
        cin >> pap[i];
    }

    int res = 0;
    int count_1 = 0;  // it will keep counting the number of one
    int sum_term = 0; // it will store each 1 will do the how many combination with 2 

    for (int i = 0; i < n; i++) {
        if (pap[i] == 1) {
            sum_term = (sum_term + 1) % p; // new 1 added to the combination
            count_1 = (count_1 + 1) % p;
        } 
        else if (pap[i] == 2) {
            sum_term = (sum_term * 2) % p; // basically takeing of each 2 as two posibility like either take that 2 or not
        } 
        else if (pap[i] == 3) {
            int to_add = (sum_term - count_1 + p) % p; // sum_term store all the possible combination of takeing 2 with one 1 value, for each one there is one case where it is not takeing any 2 , those case will be decrease that's why number of one count is minus
            res = (res + to_add) % p;
        }
    }

    cout << res << endl;
}

int32_t main()
{
    auto begin = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    InverseofNumber(p);
    InverseofFactorial(p);
    factorial(p);
    int t = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);

    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}