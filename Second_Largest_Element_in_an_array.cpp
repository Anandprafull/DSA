#include <bits/stdc++.h>
using namespace std;

// Problem Statement: Given an array, find the second smallest and second largest element in the array. Print ‘-1’ in the event that either of them doesn’t exist.

/*Brute Force approach: Sort the array in ascending order and return the 2nd last element of the array.

Disclaimer: It only works when there are no duplicates

Time complexity: O(nlogn)
Space complexity: O(1)

void getElements(int arr[], int n){
    if(n==0 || n==1)
       { cout<<-1<<" "<<-1<<endl;
       return;
       }

    sort(arr, arr+n);
    int small=arr[1];
    int large=arr[n-2];
    cout<<"Second smallest is "<<small<<endl;
    cout<<"Second largest is "<<large<<endl;
}
int main(){
    int arr[]={1,5,3,7,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    getElements(arr,n);
    return 0;
}*/

/*
Solution 2 (Better Solution)
    Intuition:
    Even though we want to have just the second smallest and largest elements, we are still sorting the entire array for that and thus increasing the time complexity. Can we somehow try to not sort the array and still get our answer?

    Approach:
    1. Find the smallest and largest element in the array in a single traversal.
    2. After this, we once again traverse the array and find an element that is just greater than the smallest element we just found.
    3. Similarly, we would find the largest element which is just smaller than the largest element we just found.
    4. Indeed, this is our second smallest and second largest element.


void getElements(int arr[], int n)
{
    if (n == 0 || n == 1)
    {
        cout << -1 << " " << endl;
        return;
    }
    int small=INT_MAX,second_small=INT_MAX;
    int large=INT_MIN,second_large=INT_MIN;
    int i;
    for(i=0;i<n;i++){
        small=min(small,arr[i]);
        large=max(large,arr[i]);
    }
    for(i=0;i<n;i++)
    {
        if(arr[i]<second_small && arr[i]!=small)
            second_small=arr[i];
        if(arr[i]>second_large && arr[i]!=large)
            second_large=arr[i];
    }
     cout<<"Second smallest is "<<second_small<<endl;
    cout<<"Second largest is "<<second_large<<endl;  
}
int main()
{
    int arr[]={1,2,4,6,7,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    getElements(arr,n);
    return 0;
}
// Time Complexity: O(N), two linear traversals in array
// Space Complexity: O(1)*/


/* Optimal Approach: In the previous solution, even though we were able to bring down the time complexity to O(N), we still needed to do two traversals to find our answer. Can we do this in a single traversal by using smart comparisons on the go?

Approach:
We would require four variables: small, second_small, large, and second_large. Variable small and second_small are initialized to INT_MAX while large and second_large are initialized to INT_MIN.

Second Smallest Algorithm:
1. If the current element is smaller than 'small', then we update second_small and small variables.
2. Else if the current element is smaller than 'second_small', then we update the variable 'second_small'.
3. Once we traverse the entire array, we would find the second smallest element in the variable second_small.

Second Largest Algorithm:
1. If the current element is larger than 'large', then update second_large and large variables.
2. Else if the current element is larger than 'second_large', then we update the variable second_large.
3. Once we traverse the entire array, we would find the second largest element in the variable second_large.
*/


int secondSmallest(int arr[],int n)
{
    if(n<2)
        return -1;
    int small = INT_MAX;
    int second_small = INT_MAX;
    int i;
    for(i = 0; i < n; i++) 
    {
       if(arr[i] < small)
       {
          second_small = small;
          small = arr[i];
       }
       else if(arr[i] < second_small && arr[i] != small)
       {
          second_small = arr[i];
       }
    }
   return second_small;     
}
int secondLargest(int arr[],int n)
{
	if(n<2)
	return -1;
    int large=INT_MIN,second_large=INT_MIN;
    int i;
    for (i = 0; i < n; i++) 
    {
        if (arr[i] > large) 
        {
            second_large = large;
            large = arr[i];
        }
 
        else if (arr[i] > second_large && arr[i] != large) 
        {
            second_large = arr[i];
        }
    }
    return second_large;                
}

int main() {
    int arr[]={1,2,4,7,7,5};  
    int n=sizeof(arr)/sizeof(arr[0]);
        int sS=secondSmallest(arr,n);
        int sL=secondLargest(arr,n);
    cout<<"Second smallest is "<<sS<<endl;
    cout<<"Second largest is "<<sL<<endl;
    return 0;
}

// Time Complexity: O(N), Single-pass solution

// Space Complexity: O(1)
