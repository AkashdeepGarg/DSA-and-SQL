// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int kthLargest(vector<int> &Arr,int N,int K){
        vector<int> sum;
        int s = 0;
        for(int i=0;i<N;i++){
            sum.push_back(Arr[i]);
            s=Arr[i];
            for(int j=i+1;j<N;j++){
                s = s+Arr[j];
                sum.push_back(s);
            }
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0;i<sum.size();i++){
            //cout<<sum[i]<<" ";
            pq.push(sum[i]);
            if(pq.size()>K){
                pq.pop();
            }
        }
        //cout<<endl;
        return pq.top();
    }
};

// { Driver Code Starts.

int main(){
    
    int T;
    cin>>T;
    while(T--){
        int N,K;
        cin>>N;
        cin>>K;
        vector<int> Arr(N);
        for(int i=0;i<N;i++){
            cin>>Arr[i];
        }
        Solution ob;
        int ans=ob.kthLargest(Arr,N,K);
        cout<<ans<<endl;
    }
    return 0;
}  // } Driver Code Ends