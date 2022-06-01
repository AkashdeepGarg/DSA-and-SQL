// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        int n=x.length();
        stack<char> s;
        for (int i = 0; i < n; i++)
        {
            if (x[i] == '(' || x[i] == '{' || x[i] == '[')
              s.push(x[i]);
            if (!s.empty())
             {
              if (x[i] == ')')
              {
               if (s.top() == '(')
               {
                s.pop();
                continue;
               }else
                break;
              }
          //
          if (x[i] == ']')
          {
           if (s.top() == '[')
           {
            s.pop();
            continue;
           }
           else
            break;
          }
          //
          if (x[i] == '}')
          {
           if (s.top() == '{')
           {
            s.pop();
            continue;
           }
           else
            break;
          }
         }
         else
         {
          return false;
         }
        }
        return s.empty() ? true:false;
    }

};

// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends