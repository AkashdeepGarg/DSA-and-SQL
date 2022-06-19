// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
      int sum=1;
     int counter=1;
     sort(arr,arr+N);
         
         for(int i=1;i<N;i++){
         if(arr[i-1]==arr[i])
{
   continue;
}
             if(arr[i-1]+1==arr[i]  ){
                 counter++;
               sum=max(sum,counter);
               
             }

 

             else{
                counter=1;
             }
             
             
         }
         return sum;
    }
};

// { Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}  // } Driver Code Ends