#include <bits/stdc++.h>
using namespace std;

int lowerBoundd(vector<int> arr, int n, int x)
{
     int low = 0, high = n - 1, ans = n;
    while (low <= high)
    {
       
        int mid = (low + high) / 2;

        if (arr[mid] > x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 82, 99};
    int x = 78;
    cout << "lb is" << lowerBoundd(arr, arr.size(), x)<<endl;
    return 0;
}
