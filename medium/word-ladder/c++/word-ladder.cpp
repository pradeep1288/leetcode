class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        
        // Using a map for two purposes: 
        //   1) store the distince so far.
        //   2) remove the duplication 
        map<string, int> dis;
        dis[start] = 1;
        
        dict.insert(end);
        
        queue<string> q;
        q.push(start);
        
        while(!q.empty()){

            string word = q.front(); 
            q.pop();
            
            if (word == end) {
                break;
            }
            
            for (int i=0; i<word.size(); i++){
                string temp = word;
                for(char c='a'; c<='z'; c++){
                    temp[i] = c;
                    if (dict.count(temp)>0 && dis.count(temp)==0){
                        dis[temp] = dis[word] + 1;
                        q.push(temp);
                    }
                }
            }
        }
        return (dis.count(end)==0) ? 0 : dis[end];
        
    }
};
