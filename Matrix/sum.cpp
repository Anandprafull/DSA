//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    public:
    //Function to add two matrices.
    vector<vector<int> > sumMatrix( const vector<vector<int> >& A, const vector<vector<int> >& B)
    {
        // code here
        if(A.size()!=B.size() || A[0].size()!=B[0].size()){
            return {};
        }
        int rows=A.size();
        int cols=A[0].size();
        vector<vector<int>> C(rows, vector<int>(cols,0));
        
        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                C[i][j]=A[i][j]+B[i][j];
            }
        }
        return C;
    }

};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > A(row); 
        for(int i=0; i<row; i++)
        {
            A[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>A[i][j];
            }
        }
        cin>> row>> col;
        vector<vector<int> > B(row);
        for(int i=0; i<row; i++)
        {
            B[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>B[i][j];
            }
        }
        Solution ob;
        vector<vector<int> > result = ob.sumMatrix(A,B);
        if(result.size() == 0)
            cout<<"-1";
        else
        {
            for (int i = 0; i < result.size(); ++i)
            {
                for (int j = 0; j < result[0].size(); ++j)
                {
                    cout<<result[i][j]<<" ";
                }
            }
        }
        cout<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends
