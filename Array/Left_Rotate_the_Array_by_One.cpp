#include<bits/stdc++.h>
using namespace std;

//Problem Statement: Given an array of N integers, left rotate the array by one place.

/* Brute force Approach
Intuition:
The rotated array has just a difference that its first element is present at the last index of the array. So if we can just store the element at the first index and then shift all the elements towards the left and at last put the stored element at the last index. We will get th rotated array.

Approach:
We can take another dummy array of the same length and then shift all elements in the array toward the left and then at the last element store the index of 0th index of the array and print it.

Time Complexity: O(n), as we iterate through the array only once.
Space Complexity: O(n) as we are using another array of size, same as the given array.


void solve(int arr[], int n){
    int temp[n];
    for (int i=1;i<n;i++){
        temp[i-1]=arr[i];
    }
    temp[n-1]=arr[0];
    for(int i=0;i<n;i++){
        cout<<temp[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int n=5;
    int arr[]={1,2,3,4,5};
    solve(arr,n);
} */

/*Optimal Approach: 
Here, in the given array :n = 5, arr[] = {1,2,3,4,5}

At first, we have to shift the array towards the left so, we store the value of the first index in a variable (let it be x).

Then we iterate the array from the 0th index to the n-1th index(why n-1 i will explain it below)

And then store the value present in the next index to the current index like this :

arr[i] = arr[i+1]
And to prevent its segmentation fault we will iterate it till n-1.

At last, put the value of variable x in the last index of the array.

Time Complexity: O(n), as we iterate through the array only once.
Space Complexity: O(1) as no extra space is used*/

void solve(int arr[], int n){
    int temp = arr[0];
    for(int i=0;i<n-1;i++){
        arr[i]=arr[i+1];
    }
    arr[n-1]=temp;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int n=5;
    int arr[]={1,2,3,4,5};
    solve(arr,n);
}