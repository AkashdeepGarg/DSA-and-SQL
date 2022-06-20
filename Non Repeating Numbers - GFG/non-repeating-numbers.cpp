// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        vector<int> res;
        int ans=nums[0];
        int n = nums.size();
        for(int i=1;i<n;i++){
            ans=ans^nums[i];
        }
        int rightbit = ans&~(ans-1);
        int a=0,b=0;
        for(int i=0;i<n;i++){
            if(rightbit&nums[i])
            b=b^nums[i];
            else
            a=a^nums[i];
        }
        res.push_back(a);
        res.push_back(b);
        sort(res.begin(),res.end());
        return res;
    }
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}  // } Driver Code Ends