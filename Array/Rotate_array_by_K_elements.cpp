#include<bits/stdc++.h>
using namespace std;

//Problem Statement: Given an array of integers, rotating array of elements by k elements either left or right.

/*Approach 1: Using a temp array 

For Rotating the Elements to right
Step 1: Copy the last k elements into the temp array.

Step 2: Shift n-k elements from the beginning by k position to the right

Step 3: Copy the elements into the main array from the temp array.


void rotateRight(int arr[], int n, int k)
{
    if(n==0)
        return;
    k=k%n;
    if (k>n)
        return;
    int temp[k];
    for (int i=n-k;i<n;i++)
    {
        temp[i-n+k]=arr[i];
    }
    for(int i=n-k-1;i>=0;i--)
    {
        arr[i+k]=arr[i];
    }
    for(int i=0;i<k;i++)
    {
        arr[i]=temp[i];
    }
}
int main()
{
    int n=7;
    int arr[]={1,2,3,4,5,6,7};
    int k=2;
    rotateRight(arr,n,k);
    cout<<"After rotating the elements to right"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
Time Complexity: O(n)
Space Complexity: O(k) since k array element needs to be stored in temp array*/

/*For Rotating the Elements to left
Step 1: Copy the first k elements into the temp array.

Step 2: Shift n-k elements from last by k position to the left

Step 3: Copy the elements into the main array from the temp array.

void rotateLeft(int arr[], int n, int k)
{
    if(n==0)
    return;
    k=k%n;
    if (k>n)
        return;
    int temp[k];
    for(int i=0;i<k;i++)
    {
        temp[i]=arr[i];
    }
    for(int i=0;i<n-k;i++)
    {
        arr[i]=arr[i+k];
    }
    for(int i=n-k;i<n;i++)
    {
        arr[i]=temp[i-n+k];
    }
}
int main()
{
    int n=7;
    int arr[]={1,2,3,4,5,6,7};
    int k=2;
    rotateLeft(arr,n,k);
    cout<<"After rotating the elements to left "<<endl;
    for (int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
Time Complexity: O(n)
Space Complexity: O(k) since k array element needs to be stored in temp array
*/

/*Approach 2: Using ” Reversal Algorithm “
For Rotating Elements to right
Step 1: Reverse the last k elements of the array

Step 2: Reverse the first n-k elements of the array.

Step 3: Reverse the whole array.

*/
