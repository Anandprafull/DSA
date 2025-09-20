#include <bits/stdc++.h>
using namespace std;

/*
    35. Search Insert Position
    
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0,h=n-1,ans=n;
        while(l<=h){
            int m=(l+h)/2;
            if(nums[m]>=target){
                ans=m;
                h=m-1;
            }else{
                l=m+1;
            }
        }
        return ans;
    }
};
*/

int lowerBoundd(vector<int> arr, int n, int x)
{
     int low = 0, high = n - 1, ans = n;
    while (low <= high)
    {
       
        int mid = (low + high) / 2;

        if (arr[mid] >= x)
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
