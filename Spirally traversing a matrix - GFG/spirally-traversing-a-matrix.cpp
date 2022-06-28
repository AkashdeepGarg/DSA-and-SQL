// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > A, int r, int c) 
    {
        vector<int> res;
        // code here
        int top=0,bottom=r-1,right=c-1,left=0;
      while(top<=bottom && left<=right){
          for(int i=left;i<=right;i++){
              res.push_back(A[top][i]);
          }
          top++;
          for(int i=top;i<=bottom;i++){
              res.push_back(A[i][right]);
          }
          right--;
          if(top<=bottom){
          for(int i=right;i>=left;i--){
              res.push_back(A[bottom][i]);
          }
          bottom--;
          }
          if(left<=right){
              for(int i=bottom;i>=top;i--){
                  res.push_back(A[i][left]);
              }
              left++;
          }
      }
      return res;
    }
    
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends