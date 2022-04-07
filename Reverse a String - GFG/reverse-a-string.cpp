// { Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;


string reverseWord(string str);


int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	string s;
	cin >> s;
	
	cout << reverseWord(s) << endl;
	}
	return 0;
	
}

// } Driver Code Ends


//User function Template for C++

string reverseWord(string str){
   int l=str.length();
   int high=l-1,low=0;
   
   for(int i=0;i<l/2;i++){
       swap(str[low],str[high]);
       low++;
       high--;
   }
   return str;
    
  //Your code here
}