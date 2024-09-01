#include<bits/stdc++.h>
using namespace std;

// Problem Statement: Given an array, we have to find the largest element in the array.

/*Brute Force approach: Sort the array in ascending order and return the last element of the array.
Time complexity: O(nlogn) where n is the size of the array.
Space complexity: O(n)

int sortArray(vector<int> arr){
    sort(arr.begin(), arr.end());
    return arr[arr.size()-1];
}
int main(){
    vector<int> arr1 = {2,8,7,5,1};
    vector<int> arr2 = {1,7,3,6,5};

    cout<<"The largest element in the array is: "<<sortArray(arr1)<<endl;
      cout<<"The largest element in the array is: "<<sortArray(arr2)<<endl;

    return 0;
}*/

/*Recursive Approach: Declare and update a max variable while looping

Time Complexity: O(n)
Space Complexity: O(1

int findLargestElement(int arr[], int n){
    int max=arr[0];
    for(int i=0;i<n;i++){
        if(max<arr[i]){
            max=arr[i];
        }
    }
    return max;
}
int main(){
    int arr1[] = {2,5,1,8,6};
    int n=5;
    int max= findLargestElement(arr1, n);
    cout<<"Largest element is "<<max<<endl;
}

*/
