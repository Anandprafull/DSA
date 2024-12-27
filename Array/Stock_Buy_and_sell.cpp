#include<bits/stdc++.h>
using namespace std;

int maxProfit(int price[],int start, int end)
{
    if(end<=start)
    return 0;
    int profit=0;
    for(int i=start;i<end;i++)
    {
        for(int j=i+1;j<=end;j++)
        {
            if(price[j]>price[i])
            {
                int currentProfit=price[j]-price[i]+maxProfit(price,start,i-1)+maxProfit(price,j+1,end);
                profit=max(profit,currentProfit);
                
            }
        }
    }
    return profit;
}
int main()
{
	int price[] = { 100, 180, 260, 310, 40, 535, 695 };
	int n = sizeof(price) / sizeof(price[0]);

	cout << maxProfit(price, 0, n - 1);

	return 0;
}
/*Time Complexity: O(N2), Trying to buy every stock and exploring all possibilities.
Auxiliary Space: O(1)*/

// -------------------------------------------------------------------------------

//Valley Peak Approach
/*Time Complexity: O(N), Traversing over the array of size N.
Auxiliary Space: O(1)*/
#include<bits/stdc++.h>
using namespace std;

int maxProfit(int price[] , int n)
{
    int profit=0;
    for(int i=1;i<n;i++)
    {
    if(price[i]>price[i-1])
    {
        profit +=(price[i]-price[i-1]);
    }
    }
    return profit;
}
int main()
{
	int price[] = { 100, 180, 260, 310, 40, 535, 695 };
	int n = sizeof(price) / sizeof(price[0]);

	cout << maxProfit(price, n);

	return 0;
}
