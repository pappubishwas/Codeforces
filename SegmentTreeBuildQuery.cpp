#include <bits/stdc++.h>
using namespace std;
int a[100005], seg[4 * 100005];
void build(int idx,int l,int h){
    if(l==h){
        seg[idx]=a[l];
        return;
    }
    int mid=(l+h)/2;
    build(2*idx+1,l,mid);
    build(2*idx+2,mid+1,h);
    seg[idx]=max(seg[2*idx+1],seg[2*idx+2]);
}

int query(int idx,int low,int high,int l,int r){
        if(low>=l && high<=r){
            return seg[idx];
        }
        if(low>r || high<l) return INT_MIN;
        int mid=(low+high)/2;
        int left=query(2*idx+1,low,mid,l,r);
        int right=query(2*idx+2,mid+1,high,l,r);
        return max(left,right);
}
int main()
{
    int n;
    cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    build(0,0,n-1);
    int q;
    cin>>q;

    while (q--)
    {
        int l,r;
        cin>>l>>r;
        cout<<query(0,0,n-1,l,r)<<endl;
    }
    
    return 0;
}
