// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    /*int matrix(int arr[],int i, int j){
        if(i>=j){
            return 0;
        }
        int mn = INT_MAX;
        for(int k=i;k<=j-1;k++){
            int temp = matrix(arr,i,k) + matrix(arr,k+1,j) + arr[i-1]*arr[k]*arr[j];
            if(temp<mn){
                mn = temp;
            }
        }
        return mn;
    }*/
    int t[101][101];
    
    int matrix(int arr[],int i, int j){
        if(i>=j){
            return 0;
        }
        if(t[i][j]!=-1){
            return t[i][j];
        }
        int mn = INT_MAX;
        for(int k=i;k<=j-1;k++){
            int temp = matrix(arr,i,k) + matrix(arr,k+1,j) + arr[i-1]*arr[k]*arr[j];
            if(temp<mn){
                mn = temp;
            }
        }
        return t[i][j]=mn;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code her
        memset(t,-1,sizeof(t));
        int i = 1;
        int j = N-1;
        return matrix(arr,i,j);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends