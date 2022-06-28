// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    long long solve(long long A[],long long N,long long k){
        priority_queue<long long> mx;
        for(long long i=0;i<N;i++){
            mx.push(A[i]);
            if(mx.size()>k){
                mx.pop();
            }
        }
        return mx.top();
    }
    long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2)
    {
        // Your code goes here
        long long a = solve(A,N,K1);
        long long b = solve(A,N,K2);
        long long sum=0;
        for(long long i=0;i<N;i++){
            if(A[i]>a && A[i]<b){
                sum+=A[i];
            }
        }
        
        return sum;
    }
};

// { Driver Code Starts.
int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n;
        long long a[n+5];
        for(int i =0;i<n;i++)
            cin >> a[i];
        
        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
        
    }
	return 0;
}
  // } Driver Code Ends