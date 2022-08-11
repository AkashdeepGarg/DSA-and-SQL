class comp{
    public:
    bool operator()(pair<int, string>& a , pair<int, string>& b){
        if (a.first == b.first){
            return a.second > b.second;
        }
        else return a.first < b.first;
    }
};

class Solution {
public:    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> cnt;
        for(auto x:words){
            cnt[x]++;
        }
        vector<string> out;
        priority_queue<pair<int, string>, vector<pair<int, string>>, comp> pq;
        for(auto x:cnt){
            pq.push({x.second, x.first});
        }
        int i=0;
        while(!pq.empty()){
            i++;
            out.push_back(pq.top().second);
            pq.pop();
            if (i == k) break;
        }
        return out;
    }
};