class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> arr = {1};
        
        for(int i = 1; i < rowIndex+1 ; i++)
        {
            vector<int> temp(i+1,1);
            for(int j = 1 ; j < i ; j++)
            {
                temp[j] = arr[j-1]+arr[j];   
            }
            arr = temp;
        }
        return arr;
    }
};