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
    cin >>n>> q;
    string s;
    cin>> s;
    int qq=0;
    for(auto ch:s) if(ch=='?') qq++; // total options

    int t1=0;  // V/X
    int t2=0;  // I
    int t3=0;  // anything 
    int t4=0;  // both

    for(int i=0;i<n;i++){
        if(s[i]=='?'){ // ? found 
            int j=i;
            while(j+1<n && s[j+1]==s[i]) j++; // find the length of the block where all the elsement is ?

            bool ls=false,re=false; 
            if(i>0 && s[i-1]=='I') ls=true; // left side has I , so we can use V/X to reduce
            if(j+1<n && s[j+1]!='I') re=true; // right side has V/X , we can add I before it
            int len=j-i+1; // length of the block
            if(len==1){ // len 1
                if(ls && re) t3++;//anything we can give here it will reduce
                else if(ls) t1++; // we can add V/X on left most ?
                else if(re) t2++; // we can add I on right most ?
            }else{
                if(ls) t1++,len--; // we can add V/X on left most ?
                if(re) t2++,len--; // we can add I on right most ?
                t4+=len/2; // for each two position we can reduce by useing IV or IX
            }
            i=j;
        }
    }

    int base=0;
    for(int i=0;i<n;i++){
        if(s[i]=='I') base++;
        else if(s[i]=='V') base+=5;
        else if(s[i]=='X') base+=10;
    }

    for(int i=0;i+1<n;i++){
        if(s[i]!='?' && s[i+1]!='?' && s[i]=='I' && s[i+1]!='I'){
            base-=2;
        }
    }

    while(q--){
        int cx,cv,ci;
        cin>> cx>>cv>>ci;
        ci=min(ci,qq); //maximum number of I
        cv=min(cv,qq-ci); //  2nd maximum number of V
        cx=min(cx,qq-cv-ci); // rest number of X
        int ans=base;
        ans+=ci+cv*5+cx*10; // total sum added
        cv+=cx; // total V/X used
        ans-=t3*2; // total t3 points will be IX/IV
        
        int use=min(t1,cv); // total positions created by using X/V where IV/IX created
        cv-=use; // used cv
        ans-=use*2; 
        
        use=min(t2,ci); // total positions created by using I where  IV/IX created
        ci-=use;
        ans-=use*2;

        use=min({t4,ci,cv}); // total IV or IX created by min number of ci,cv,t4 
        ans-=use*2;

        cout<<ans<<endl;
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