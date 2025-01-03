class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result(2,0);
        int i=0,j=numbers.size()-1;
        while(i<j){
            int temp = numbers[i] + numbers[j];
            if(temp == target){
                result[0] = i+1;
                result[1] = j+1;
                break;
            }
            else if(temp < target){
                i++;
            }
            else{
                j--;
            }
        }
        return result;
    }
};