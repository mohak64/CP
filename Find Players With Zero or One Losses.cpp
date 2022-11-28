class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int>loss;
        unordered_map<int,int>win;
        for(auto it: matches){
            loss[it[1]]++;
             win[it[0]]++;
        }
        vector<vector<int>> ans;
        vector<int>temp;
        for(auto it: loss){
            if(it.second==1){
                temp.push_back(it.first);
            }
        }
        
        vector<int>tmp2;
        for(auto it:win){
            if(it.first>=1){
                if(loss.find(it.first)==loss.end()){
                    tmp2.push_back(it.first);
                }
            }
          } 
        sort(tmp2.begin(),tmp2.end());
        sort(temp.begin(),temp.end());
        
        ans.push_back(tmp2);
        ans.push_back(temp);
        
        return ans;
    }
};
