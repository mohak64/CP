class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        
        // create graph
        vector<vector<int>> g(n);
        for(auto e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        
        
        int ans = INT_MIN;
        
        // we going to each node and calculate max sum of at most k edges connected centered node
        // given question says maximum sum of node vals with at most k edges so we neglacting negaticve vals to connected centerd node 
        for(int i = 0; i < n; i++) {
            priority_queue<int, vector<int>, greater<int>> pq;
            
            int tt = vals[i];  // adding centered node value
            
            for(int u : g[i]) {
                pq.push(vals[u]);              
                if(pq.size() > k) pq.pop();  // calculate max values of k nodes connected to centered node
            }
  
            while(!pq.empty()){ 
                if(pq.top() > 0) tt += pq.top();  // we only add positive values. suppose centered node connected all -ve vals so in that case only centered node vals is max sum with zero edges
                pq.pop(); 
            }
            
            ans = max(tt, ans);
        }
        
        return  ans;
    }
};
