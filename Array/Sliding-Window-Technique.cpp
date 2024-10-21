#include <iostream>
#include <vector>
#include <algorithm> // for max

using namespace std;

int maxSumSubarray(const vector<int>& arr, int k) {
    int n = arr.size();
    if (n < k) {
        return -1;
    }

    // Compute the sum of the first window
    int window_sum = 0;
    for (int i = 0; i < k; ++i) {
        window_sum += arr[i];
    }

    int max_sum = window_sum;

    // Slide the window over the array
    for (int i = k; i < n; ++i) {
        window_sum = window_sum - arr[i - k] + arr[i];
        max_sum = max(max_sum, window_sum);
    }

    return max_sum;
}

int main() {
    vector<int> arr = {1, 4, 2, 10, 23, 3, 1, 0, 20};
    int k = 4;
    cout << "Maximum sum of subarray of size " << k << " is " << maxSumSubarray(arr, k) << endl;
    return 0;
}