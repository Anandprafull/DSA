// C++ program to illustrate the above functions

#include <iostream> 
#include <vector> 

using namespace std; 

int main() 
{ 
    vector<int> v; 
    
    // Push elements 
    for (int i = 1; i <= 5; i++) 
        v.push_back(i); 

    cout << "Size : " << v.size(); 
    
    // checks if the vector is empty or not 
    if (v.empty() == false) 
        cout << "\nVector is not empty"; 
    else
        cout << "\nVector is empty"; 

    cout << "\nOutput of begin and end: "; 
    for (auto i = v.begin(); i != v.end(); ++i) 
        cout << *i << " "; 
        
    // inserts at the beginning 
    v.emplace(v.begin(), 5); 
    cout << "\nThe first element is: " << v[0]; 
  
    // Inserts 20 at the end 
    v.emplace_back(20); 
    int n = v.size(); 
    cout << "\nThe last element is: " << v[n - 1]; 
  
    // erases the vector 
    v.clear(); 
    cout << "\nVector size after erase(): " << v.size();     

    return 0; 
}
/*Size : 5
Vector is not empty
Output of begin and end: 1 2 3 4 5 
The first element is: 5
The last element is: 20
Vector size after erase(): 0*/
