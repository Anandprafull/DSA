#include<iostream>
#include<iterator> 
#include<vector>

using namespace std;
int main()
{
    vector<int> arr = {1,2,3,4,5};
    //Declaring iterator to a vector
    vector <int>::iterator ptr;
    //Displaying vector elements using begin() and end()
    cout<<"The vector elements are : ";
    for (ptr = arr.begin(); ptr < arr.end(); ptr++)
      cout<<*ptr<<" ";
    return 0;
}
/*
Output
The vector elements are : 1 2 3 4 5 
*/
