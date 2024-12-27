//Given a fixed array and multiple range sum, how to answer the queries efficiently
//Naive Solution
#include <iostream>
#include <cmath>
using namespace std;

int getSum(int arr[], int l, int r){
    int res= 0;
    for(int i=l; i<=r; i++)
        res+= arr[i];
    return res;
}

int main(){
    int arr[]={2, 8, 3, 9, 6, 5};
    cout<<getSum(arr,1,3);
    return 0;
}
