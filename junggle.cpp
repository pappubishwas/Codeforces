// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution {
  public:
    vector<int> juggling(vector<vector<int>> &arr,int n) {
        vector <int> res;
        int a=0,b=0,c=0,j,i;
        int k=1;
        for(i=0;i<n;i++){
                if(arr[i][0]==k){
                    k=arr[i][1];
                    if(k==arr[i][2])a++;
                }else if(arr[i][1]==k){
                    k=arr[i][0];
                    if(k==arr[i][2])a++;
                }else{
                    if(k==arr[i][2])a++;
                }
            
            
        }
        k=2;
        for(i=0;i<n;i++){
                if(arr[i][0]==k){
                    k=arr[i][1];
                    if(k==arr[i][2])b++;
                }else if(arr[i][1]==k){
                    k=arr[i][0];
                    if(k==arr[i][2])b++;
                }else{
                    if(k==arr[i][2])b++;
                }
            
            
        }
        k=3;
        for(i=0;i<n;i++){
                if(arr[i][0]==k){
                    k=arr[i][1];
                    if(k==arr[i][2])c++;
                }else if(arr[i][1]==k){
                    k=arr[i][0];
                    if(k==arr[i][2])c++;
                }else{
                    if(k==arr[i][2])c++;
                }
            
            
        }
        if(a>=b && a>=c){
            res.push_back(1);
            res.push_back(a);
        }
        else if(b>a && b>=c){
            res.push_back(2);
            res.push_back(b);
        }else{
            res.push_back(3);
            res.push_back(c);
        }
        return res;
    }
};


// { Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<vector<int>> arr(n, vector<int>(3));
        for(int i=0;i<n;i++){
            for(int j=0;j<3;j++){
                cin>>arr[i][j];
            }
        }
        
        Solution obj;
        vector<int> res = obj.juggling(arr, n);
        
        cout<<res[0]<<" "<<res[1]<<endl;
        
    }
}
  // } Driver Code Ends