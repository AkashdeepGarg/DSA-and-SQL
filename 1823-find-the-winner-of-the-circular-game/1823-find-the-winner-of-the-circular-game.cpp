class Solution {
public:
//     int ans(vector<int> &res,int k){
//         if(res.size()==1){
//             return res[0];
//         }
//         int j = k%res.size();
//         res.remove(res.begin()+j);
        
        
//     }
    
    int findTheWinner(int n, int k) {
        // vector<int> v(n);
        // for(int i=0;i<n;i++){
        //     v[i]=i+1;
        // }
        // if(n==0){
        //     return 0;
        // }
        // return ans(v,k);
        
        queue<int> pq;
        for(int i=1;i<=n;i++){
            pq.push(i);
        }
        while(pq.size()>1){
            for(int i=k;i>1;i--){
                int j = pq.front();
                pq.pop();
                pq.push(j);
            }
            pq.pop();
        }
        return pq.front();
    }
};