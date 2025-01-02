//advance() :- This function is used to increment the iterator position till the specified number mentioned in its arguments.

#include<stdio.h>
#include<iterator>
#include<vector>>

using namespace std;
int main()
{
  vector<int> arr={1,2,3,4,5};
  vector<int>::itterator ptr =arr.begin();

  advance(ptr,3);

  cout<<"The position of iterator after advancing is :";
  cout<<*ptr<<" ";
/*
Output
The position of iterator after advancing is : 4 
*/
  return 0;
}
/*
Output
The position of iterator after advancing is : 4 
  */
