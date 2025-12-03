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
int mod = 998244353;

void solve()
{
    int n, q, k;
    cin >> q;
    deque<int> dq;
    int rizz = 0, el = 0, sum = 0, sum2 = 0;
    bool rev = false;
    while (q--)
    {
        int s;
        cin >> s;
        if (s == 3)
        {
            cin >> k;
            el++;
            if (rev)
                dq.push_front(k);
            else
                dq.push_back(k);
            rizz += k * el;
            sum2 += sum;
            sum2 += (1 - el) * k;
            sum += k;
            cout << rizz << "\n";
        }
        else if (s == 1)
        {
            int last;
            if(rev){
                last=dq.front();
                dq.push_back(dq.front());
                dq.pop_front();
            }else{
                last=dq.back();
                dq.push_front(dq.back());
                dq.pop_back();
                //cout<<last<<endl;
            }
            sum2-=2*(sum-last);
            sum2+=2*(el-1)*last;
            rizz+=(sum-last);
            rizz-=(el-1)*last;
            cout << rizz << "\n";
        }
        else
        {
            rizz+=sum2;
            sum2=-sum2;
            rev=!rev;
            cout << rizz << "\n";
        }
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