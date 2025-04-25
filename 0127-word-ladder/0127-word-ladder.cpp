class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(),wordList.end());
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        s.erase(beginWord);

        while(q.size()>0){
            string temp = q.front().first;
            int dist=q.front().second;
            q.pop();

            if(temp==endWord){
                return dist;
            }

            for(int i=0;i<temp.length();i++){
                char current = temp[i];
                for(char ch='a';ch<='z';ch++){
                    temp[i] = ch;
                    if(s.find(temp) != s.end()){
                        q.push({temp,dist+1});
                        s.erase(temp);
                    }
                }
                temp[i] = current;
            }
        }

        return 0;
    }
};