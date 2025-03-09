//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends



class Solution
{   
    public:
    //Function to return list of integers visited in snake pattern in matrix.
    vector<int> snakePattern(vector<vector<int> > matrix)
    {   
        // code here
        vector<int>result;
        int R=matrix.size();
        if(R==0)return result;
        int C=matrix[0].size();

        for(int i=0;i<R;i++){
        if(i%2==0){
            for(int j=0;j<C;j++){
                result.push_back(matrix[i][j]);
            }
        }
        else{
            for(int j=C-1;j>=0;j--){
            result.push_back(matrix[i][j]);
            }
        }
        
        }
        return result;
    }
    
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(n, 0);
            for( int j=0; j<n; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.snakePattern(matrix);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends
