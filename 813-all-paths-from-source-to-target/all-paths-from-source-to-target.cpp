class Solution {
public:
    void dfs(int node, vector<vector<int>>& graph, vector<vector<int>>& ans, vector<int>& curr){
        curr.push_back(node);

        if(node == graph.size() - 1){
            ans.push_back(curr);
        } 
        else{
            for(int next : graph[node]){
                dfs(next, graph, ans, curr);
            }
        }

        curr.pop_back(); // backtrack
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> curr;

        dfs(0, graph, ans, curr);

        return ans;
    }
};