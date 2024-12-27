#include <bits/stdc++.h>
using namespace std;

void moveToEnd(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[j] != 0)
                {
                    swap(arr[i], arr[j]);
                    break; // Break after swapping to avoid multiple swaps for the same zero
                }
            }
        }
    }
}

int main()
{
    int arr1[] = {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0, 9}; // Corrected array declaration
    int n = sizeof(arr1) / sizeof(arr1[0]); // Calculate the size of the array

    moveToEnd(arr1, n); // Corrected function call

    for (int i = 0; i < n; i++)
        cout << arr1[i] << ' '; // Corrected to use arr1

    cout << "\n";

    return 0;
}
