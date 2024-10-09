#include <iostream>
#include <cmath>
using namespace std;

// Function to delete an element x from an array arr[] of size n
int deleteEle(int arr[], int n, int x)
{
    int i = 0;

    // Loop through the array to find the element x
    for(i = 0; i < n; i++)
    {
        // If the element is found, break the loop
        if(arr[i] == x)
            break;
    }

    // If the element is not found, return the original size
    if(i == n)
        return n;

    // Shift elements to the left to fill the gap created by the deleted element
    for(int j = i; j < n - 1; j++)
    {
        arr[j] = arr[j + 1];
    }

    // Return the new size of the array
    return n - 1;
} 

int main() {
    // Initialize an array and the element to be deleted
    int arr[] = {3, 8, 12, 5, 6}, x = 12, n = 5;

    // Print the array before deletion
    cout << "Before Deletion" << endl;
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Delete the element and update the size of the array
    n = deleteEle(arr, n, x);

    // Print the array after deletion
    cout << "After Deletion" << endl;
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}