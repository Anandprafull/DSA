#include <iostream>
#include <cmath>
using namespace std;

// Function to insert an element x in arr[] of size n at position pos
int insert(int arr[], int n, int x, int cap, int pos)
{
    // If the array is already full, return n
    if(n == cap)
        return n;

    // Calculate the index where the element needs to be inserted
    int idx = pos - 1;

    // Shift elements to the right to make space for the new element
    for(int i = n - 1; i >= idx; i--)
    {
        arr[i + 1] = arr[i];
    }

    // Insert the new element at the calculated index
    arr[idx] = x;

    // Return the new size of the array
    return n + 1;
} 

int main() {
    // Initialize an array with capacity 5 and current size 3
    int arr[5], cap = 5, n = 3;

    // Assign initial values to the array
    arr[0] = 5; arr[1] = 10; arr[2] = 20;

    // Print the array before insertion
    cout << "Before Insertion" << endl;
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Element to be inserted and its position
    int x = 7, pos = 2;

    // Insert the element and update the size of the array
    n = insert(arr, n, x, cap, pos);

    // Print the array after insertion
    cout << "After Insertion" << endl;
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
//output 
/*
Before Insertion
5 10 20 
After Insertion
5 7 10 20 
*/


