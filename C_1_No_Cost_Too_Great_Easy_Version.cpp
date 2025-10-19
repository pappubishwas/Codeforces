#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());


#define MAXN 200005
vector<int> spf(MAXN + 1, 1);

void sieve()
{

    spf[0] = 0;
    for (int i = 2; i <= MAXN; i++) {
        if (spf[i] == 1) { 
            for (int j = i; j <= MAXN; j += i) {
                if (spf[j]== 1) 
                    spf[j] = i;
            }
        }
    }
}

set<int> getFactorization(int x)
{
    set<int> ret;
    while (x != 1) {
        ret.insert(spf[x]);
        x = x / spf[x];
    }
    return ret;
}


void Solve()
{
    int n, k, m,l,r;
    cin>> n;
    vector<int> pap(n),missing,b(n);
    int even=0;
    for(int i=0;i<n;i++){
        cin>>pap[i];
        if(pap[i]%2==0) even++;
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }

    if(even>=2) cout<<0<<endl;
    // else if(even==1)cout<<1<<endl;
    else{
        set<int> st;
        for(int i=0;i<n;i++){
            set<int> t=getFactorization(pap[i]);
            for(auto p: t){
                if(st.find(p)!=st.end()){
                    cout<<0<<endl;
                    return;
                }
                st.insert(p);
            }
        }
        
     
        if(st.empty()){
            cout<<2<<endl;
            return;
        }

        for(int i=0;i<n;i++){
            set<int> t=getFactorization(pap[i]+1);
            for(auto p: t){
                if(st.find(p)!=st.end()){
                    cout<<1<<endl;
                    return;
                }
            }
        }
        cout<<2<<endl;
    }
}

int32_t main()
{
    auto begin = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);
    sieve();
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case #" << i << ": ";
        Solve();
    }
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}





// #include <bits/stdc++.h>
// using namespace std;

// const int MAXVAL = 200002;
// const int INF = 1e9;

// int spf[MAXVAL];
// int minCostP[MAXVAL];
// vector<int> primes;

// void sieve() {
//     iota(spf, spf + MAXVAL, 0);
//     for (int i = 2; i * i < MAXVAL; ++i) {
//         if (spf[i] == i) {
//             for (int j = i * i; j < MAXVAL; j += i) {
//                 if (spf[j] == j) spf[j] = i;
//             }
//         }
//     }
// }

// vector<int> get_prime_factors(int n) {
//     vector<int> factors;
//     while (n > 1) {
//         int p = spf[n];
//         factors.push_back(p);
//         while (n > 1 && spf[n] == p) n /= p;
//     }
//     return factors;
// }

// void solve() {
//     int n;
//     cin >> n;
//     vector<int> a(n);
//     for (int &x : a) cin >> x;

//     for (int i = 0, tmp; i < n; ++i) cin >> tmp;

//     int ans = 2;

//     for (int val : a) {
//         auto factors0 = get_prime_factors(val);
//         for (int p : factors0)
//             if (minCostP[p] != INF)
//                 ans = min(ans, minCostP[p]);

//         auto factors1 = get_prime_factors(val + 1);
//         for (int p : factors1)
//             if (minCostP[p] != INF)
//                 ans = min(ans, minCostP[p] + 1);

//         for (int p : factors0) {
//             if (minCostP[p] == INF) primes.push_back(p);
//             minCostP[p] = min(minCostP[p], 0);
//         }

//         for (int p : factors1) {
//             if (minCostP[p] == INF) primes.push_back(p);
//             minCostP[p] = min(minCostP[p], 1);
//         }

//         if (ans == 0) break;
//     }

//     cout << ans << "\n";

//     for (int p : primes)
//         minCostP[p] = INF;
//     primes.clear();
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);

//     sieve();
//     fill(minCostP, minCostP + MAXVAL, INF);

//     int t;
//     cin >> t;
//     while (t--) solve();

//     return 0;
// }
