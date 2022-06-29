// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


 // } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
  vector<int> ps(int arr[], int n)
    {
        stack<int> st;
        vector<int> v;
        for (long long i = 0; i < n; i++)
        {
            while (!st.empty() && arr[i] <= arr[st.top()])
            {
                st.pop();
            }
            if (st.empty())
            {
                v.push_back(-1);
            }
            else
            {
                v.push_back(st.top());
            }
            st.push(i);
        }
        return v;
    }
    vector<int> ns(int arr[], int n)
    {
        stack<int> st;
        vector<int> v;
        for (long long i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[i] <= arr[st.top()])
            {
                st.pop();
            }
            if (st.empty())
            {
                v.push_back(n);
            }
            else
            {
                v.push_back(st.top());
            }
            st.push(i);
        }
          reverse(v.begin(), v.end());
        return v;
    }
    int getMaxArea(int arr[], int n)
    {
        // Your code here
        vector<int> a = ps(arr, n);
        vector<int> b = ns(arr, n);
        vector<int> c;
        for (int i = 0; i < n; i++)
        {
            c.push_back((b[i] - a[i] - 1)*arr[i]);
        }
        return *max_element(c.begin(), c.end());
    }
  
  
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        int arr[m] = {0} ;
        for(int i=0;i<m;i++)
        {
            arr[i] = M[0][i];
            
        }
        
        int res = getMaxArea(arr,m);
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(M[i][j]==1)
                {
                    // M[i][j] += M[i-1][j];
                    arr[j] += M[i][j];
                }
                else
                {
                    //M[i][j] = 0;
                    arr[j] = 0;
                }
                     
                
                //cout<<arr[j]<<" ";
                
            }
            //cout<<endl;
            int temp = getMaxArea(arr,m);
            res = max(temp,res);
            //cout<< res << endl ;
        }
        return res;
    }
};


// { Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
  // } Driver Code Ends