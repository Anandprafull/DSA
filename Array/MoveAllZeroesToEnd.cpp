/*
You are given an array of integers, your task is to move all the zeros in the array to the end of the array and move non-negative integers to the front by maintaining their order.





Brute Force Approach
Algorithm / Intuition
Solution 1:
Brute Force Approach: 
The extremely naive solution, we can think of, involves the use of an extra array. The algorithm is as follows.

Algorithm:
Suppose, there are N-X zeros and X non-zero elements in the array. We will first copy those X non-zero elements from the original array to a temporary array. 
Then, we will copy the elements from the temporary array one by one and fill the first X places of the original array. 
The last N-X places of the original array will be then filled with zero. Now, our task is completed.
*/


#include <bits/stdc++.h>
using namespace std;

vector<int> moveZeros(int n, vector<int> a) {
    //temporary array:
    vector<int> temp;
    //copy non-zero elements
    //from original -> temp array:
    for (int i = 0; i < n; i++) {
        if (a[i] != 0)
            temp.push_back(a[i]);
    }

    // number of non-zero elements.
    int nz = temp.size();

    //copy elements from temp
    //fill first nz fields of
    //original array:
    for (int i = 0; i < nz; i++) {
        a[i] = temp[i];
    }

    //fill rest of the cells with 0:
    for (int i = nz; i < n; i++) {
        a[i] = 0;
    }
    return a;
}


int main()
{
    vector<int> arr = {1, 0, 2, 3, 2, 0, 0, 4, 5, 1};
    int n = 10;
    vector<int> ans = moveZeros(n, arr);
    for (auto &it : ans) {
        cout << it << " ";
    }
    cout << '\n';
    return 0;
}

