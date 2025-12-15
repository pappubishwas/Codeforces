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

vector<int> lp;
vector<int> pr;
int N = 10000000;
void primefactor()
{
    lp.resize(N + 1, 0);
    for (int i = 2; i <= N; ++i)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
            lp[i * pr[j]] = pr[j];
    }
}

void Solve()
{
    int n;
    cin >> n;
    vector<int> pap(n);
    for (int i = 0; i < n; i++)
    {
        cin >> pap[i];
    }
    map<int, int> pf, psqf, pq;
    int ones = 0, primes = 0;
    //cout<<ones<<endl;
    for (int i = 0; i < n; i++)
    {
        if (lp[pap[i]] == pap[i])
        { // prime
            pf[pap[i]]++;
            primes++;
        }
        else if (pap[i] == (lp[pap[i]] * lp[pap[i]]))
        { // primes square
            psqf[pap[i]]++;
        }
        else if (pap[i] == (lp[pap[i]] * lp[pap[i] / lp[pap[i]]]))
        { // prime*prime
            pq[pap[i]]++;
        }
        ones += (pap[i] == 1);
    }
    int ans = 0;
    //cout<<ans<<endl;
    for(auto& it:pq){
        ans+=it.second*pf[lp[it.first]]; // pq,p
        ans+=it.second*pf[it.first/lp[it.first]]; // pq,q
        ans+= (it.second*(it.second+1))/2LL; // pq,pq
        ans+=ones*it.second; // 1, pq
    }
    int cnt=0;
    for(auto& it:pf){
        cnt+=it.second*(primes-it.second); // p,q
    }
    ans+=cnt/2; // p,q count duplicate
    for(auto& it:psqf){
        ans+=ones*it.second; // 1, p*p
        ans+=it.second*pf[it.first/lp[it.first]]; // p, p*p
        ans+=it.second*(it.second+1)/2; // p*p , p*p
    }
    cout<<ans<<endl;
}

int32_t main()
{
    auto begin = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    primefactor();
    for (int i = 1; i <= t; i++)
    {
        Solve();
    }

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    return 0;
}