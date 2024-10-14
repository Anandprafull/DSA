/*Given an array arr of size n−1 that contains distinct integers in the range of 1 to n (inclusive), find the missing element. The array is a permutation of size n with one element missing. Return the missing element.*/


//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    // Note that the size of the array is n-1
    int missingNumber(int n, vector<int>& arr) {

        // Calculate the total sum of numbers from 1 to n
        int totalSum = (n * (n + 1)) / 2;
        
        // Calculate the sum of the given array
        int arrSum = 0;
        for (int i = 0; i < n - 1; i++) {
            arrSum += arr[i];
        }
        
        // The missing number is the difference between the total sum and the array sum
        int missingEl = totalSum - arrSum;
        
        return missingEl;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n - 1);
        for (int i = 0; i < n - 1; ++i)
            cin >> arr[i];
        Solution obj;
        cout << obj.missingNumber(n, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends