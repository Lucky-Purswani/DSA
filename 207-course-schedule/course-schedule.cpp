class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        int V = numCourses;
        vector<vector<int>> adj(numCourses);

        for (auto &edge : pre) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }

        vector<int> indeg(V, 0);
        
        for(auto &i:adj){
            for(auto &node: i){
                indeg[node]++;
            }
        }
        
        queue<int> q;
        for(int i = 0;i<numCourses; i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }
        
        vector<int> ans;
        while(!q.empty()){
            int node = q.front(); q.pop();
            ans.push_back(node);
            
            for(auto &i:adj[node]){
                indeg[i]--;
                if(indeg[i] == 0) q.push(i);
            }
        }
        
        return ans.size() == numCourses;
    }
};