#include<bits/stdc++.h>
using namespace std;

//ans = n or -1
 
int c(vector<int> arr, int n, int x){
    int l=0,h=n-1,ans=n;
    while(l<=h){
        int m=(l+h)/2;
        if(arr[m]>=x){
            ans=arr[m];
            h=m-1;
        }else{
            l=m+1;
        }
    }
    return ans;
}
int f(vector<int> arr, int n, int x){
    int l=0,h=n-1,ans=n;
    while(l<=h){
        int m=(l+h)/2;
        if(arr[m]<=x){
            ans=arr[m];
            l=m+1;
        }else{
            h=m-1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {1, 2, 8, 10, 11, 12, 19};
    int x = 9;
    
    cout << "Floor of " << x << " is: " << f(arr, arr.size(), x) << endl;
    cout << "Ceil of " << x << " is: " << c(arr, arr.size(), x) << endl;
    
    return 0;
}