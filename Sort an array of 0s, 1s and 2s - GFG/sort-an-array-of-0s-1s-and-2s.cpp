// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        // coode here
        int c=0,d=0,e=0;
       for(int i=0;i<n;i++)
       {
           if(a[i]==0)
           c++;
           if(a[i]==1)
           d++;
           if(a[i]==2)
           e++;
       }
       for(int i=0;i<c;i++)
        a[i]=0;
        
        for(int i=c;i<c+d;i++)
        a[i]=1;
        
        for(int i=c+d;i<c+d+e;i++)
        a[i]=2;
    }
    
};

// { Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}

  // } Driver Code Ends