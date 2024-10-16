#include <iostream>
#include <vector>

using namespace std;

pair<int, int> findPairWithSum(const vector<int>& arr, int targetSum) {
    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
        int currentSum = arr[left] + arr[right];

        if (currentSum == targetSum) {
            return make_pair(arr[left], arr[right]);
        } else if (currentSum < targetSum) {
            left++;
        } else {
            right--;
        }
    }

    return make_pair(-1, -1); // If no such pair exists
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 6};
    int targetSum = 6;

    pair<int, int> result = findPairWithSum(arr, targetSum);
    
    if (result.first != -1 && result.second != -1) {
        cout << "Pair found: (" << result.first << ", " << result.second << ")" << endl;
    } else {
        cout << "No pair found with sum " << targetSum << endl;
    }

    return 0;
}