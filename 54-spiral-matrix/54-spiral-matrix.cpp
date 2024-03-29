class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top,down,left,right;
        top=0;
        down=matrix.size()-1;
        left=0;
        right=matrix[0].size()-1;
        int dir=0;
        int i;
        vector<int> ans;
        while(top<=down && left<=right)
        {
        if(dir==0)
        {
        for( i=left;i<=right;i++)
        ans.push_back(matrix[top][i]);
        top++;
        }
        else if(dir==1)
        {
        for(i=top;i<=down;i++)
        ans.push_back(matrix[i][right]);
        right--;
        }
        else if(dir==2)
        {
        for(i=right;i>=left;i--)
        ans.push_back(matrix[down][i]);
        down--;
        }
        else if(dir==3)
        {
        for(i=down;i>=top;i--)
        ans.push_back(matrix[i][left]);
        left++;
        }
        dir=(dir+1)%4;
        }
        return ans;
    }
};