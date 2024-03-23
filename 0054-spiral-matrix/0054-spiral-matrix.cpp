class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int l=0,r=matrix[0].size()-1;
        int u=0,d=matrix.size()-1;
        int dir=0;
        while(u<=d && l<=r)
        {
        if(dir==0)
        {
        for(int i=l;i<=r;i++)
        ans.push_back(matrix[u][i]);
        u++;
        }
        else if(dir==1)
        {
        for(int i=u;i<=d;i++)
        ans.push_back(matrix[i][r]);
        r--;
        }
        else if(dir==2)
        {
        for(int i=r;i>=l;i--)
        ans.push_back(matrix[d][i]);
        d--;
        }
        else if(dir==3)
        {
        for(int i=d;i>=u;i--)
        ans.push_back(matrix[i][l]);
        l++;
        }
        dir=(dir+1)%4;
        }
        
        return ans;
    }
};