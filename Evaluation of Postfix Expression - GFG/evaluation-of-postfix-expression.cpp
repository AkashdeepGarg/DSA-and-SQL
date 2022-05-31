// { Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string s)
{
    // Your code here
    stack<int> st;
    for(int i=0;i<s.length();i++){
        if(s[i]=='+'){
            int x=st.top();
            st.pop();
            int y=st.top();
            st.pop();
            st.push(x+y);
        }
        else if(s[i]=='-'){
            int x=st.top();
            st.pop();
            int y=st.top();
            st.pop();
            st.push(y-x);
            
        }
        else if(s[i]=='*'){
            int x=st.top();
            st.pop();
            int y=st.top();
            st.pop();
            st.push(x*y);
            
        }
        else if(s[i]=='/'){
            int x=st.top();
            st.pop();
            int y=st.top();
            st.pop();
            st.push(y/x);
            
        }
        else{
            st.push(s[i]-'0');
        }
    }
    return st.top();
    
}
};

// { Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}
  // } Driver Code Ends