#include<bits/stdc++.h>
class Solution {
public:
   struct compare
{
    bool operator()(string &a,string &b)
    {
        return a.length()==b.length() ? (a>b) : a.length()>b.length();
    }    
};

string kthLargestNumber(vector<string>& nums, int k) {
    priority_queue<string,vector<string>,compare> minHeap;
    for(int i=0;i<nums.size();i++)
    {
        minHeap.push(nums[i]);
        
        if(minHeap.size()>k)
            minHeap.pop();
    }
    return minHeap.top();
}
};