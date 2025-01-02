#include<iostream>
#include<iterator>
#include<vector>

using namespace std;
int main()
{
  vector<int> arr={1,2,3,4,5(;
  vector<int>::iterator ptr =arr.begin();
  vector<int>iterator ftr =arr.end();

  auto it = next(ptr,3);
  auto it1 = prev(ftr, 3);

  cout<<"The position of new iterator using next() is";
cout<<*it1<<" ";
cout<<endl;

return 0;
}
