#include<iostream>
using namespace std;

int search(int arr[],int n, int x){
    for(int i=0;i<n;i++){
        if(arr[i]==x)return i;
    }
    return -1;
}

int main(){
    int arr[]={20,10,4,1,17}, x=4;
    cout<<"Searched Index = "<<search(arr,5,x)<<endl;
}