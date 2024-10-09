#include <iostream>
#include <cmath>
using namespace std;

// Function to search for an element x in an array arr[] of size n
int search(int arr[], int n, int x)
{
    // Loop through each element in the array
    for(int i = 0; i < n; i++)
    {
        // If the current element matches x, return its index
        if(arr[i] == x)
            return i;
    }

    // If the element is not found, return -1
    return -1;
} 

int main() {
    // Initialize an array and the element to be searched
    int arr[] = {20, 5, 7, 25}, x = 5;

    // Call the search function and print the result
    cout << search(arr, 4, x);  
    
    return 0;
}