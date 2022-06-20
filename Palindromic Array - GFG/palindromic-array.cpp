// { Driver Code Starts
#include<iostream>
#include<string.h>
using namespace std;


 // } Driver Code Ends
/*Complete the function below*/
#include <bits/stdc++.h>
class Solution {
public:
    int PalinArray(int a[], int n)
    {
    	// code here
    	for(int i=0;i<n;i++){
    	    int b = a[i];
    	    string B = to_string(b);
    	    string C = B;
    	    reverse(B.begin(), B.end());
    	    if(B!=C)
    	    return 0;
    	}
    	
    	return 1;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		Solution obj;
		cout<<obj.PalinArray(a,n)<<endl;
	}
}  // } Driver Code Ends