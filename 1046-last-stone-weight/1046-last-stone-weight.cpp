class Solution {
public:
    int find(vector<int>& stones,int n){
        for(int i=0;i<stones.size();i++){
            if(stones[i] == n)
                return i;
        }
        return -1;
    }
    int lastStoneWeight(vector<int>& stones) {
        int a,b,i;
        while(stones.size()>1){
            a = *max_element(stones.begin(),stones.end());
            i = find(stones,a);
            stones.erase(stones.begin()+i);
            b = *max_element(stones.begin(),stones.end());
            i = find(stones,b);
            stones.erase(stones.begin()+i);
            a = a-b;
            if(a!=0){
                stones.push_back(a);
            }
            if(stones.empty())
                stones.push_back(0);
        }
        return stones[0];
    }
};