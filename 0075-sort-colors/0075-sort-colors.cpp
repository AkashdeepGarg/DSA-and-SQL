class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int i,j=n-1 ;

       int zero=0,one=0,two=0;
        for(i=0;i<n;i++)
        {
            if(nums[i]==0) 
                zero++;
            else if(nums[i]==1)  
                one++;
            else 
                two++;
        }

        for(i=0;i<n;i++)
        {
             if(i<zero) 
                 nums[i]=0;
             else if(i<one+zero)  
                 nums[i]=1;
             else 
                 nums[i]=2;
        }
    }
};