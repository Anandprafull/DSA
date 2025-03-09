//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to verify multiplication of two matrices.
    bool multiplyMatrix(int mat1[4][4], int mat2[4][4], int result[4][4]) {
        // code here
        int mat[4][4];
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                mat[i][j]=0;
                for(int k=0;k<4;k++){
                    mat[i][j]+=mat1[i][k]*mat2[k][j];
                }
            }
        }
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if(result[i][j]==mat[i][j]){
                    return true;
                }
                return false;
            }
        }
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int mat1[4][4]; // Define a 2D array for matrix A
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cin >> mat1[i][j];
            }
        }

        int mat2[4][4]; // Define a 2D array for matrix B
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cin >> mat2[i][j];
            }
        }

        Solution ob;
        int result[4][4]; // Define a 2D array for the result matrix
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cin >> result[i][j];
            }
        }
        bool isValid = ob.multiplyMatrix(mat1, mat2, result);

        if (!isValid) {
            cout << "False\n";
        } else {
            cout << "True\n";
        }
    }
    return 0;
}

// } Driver Code Ends
