class Solution {
public:
    void dfs(vector<vector<int>> &adjM, vector<int> &vis, int node){
        vis[node] = 1;
        for(int i = 0; i<adjM[node].size(); i++){
            if(adjM[node][i] == 1 && !vis[i]){
                dfs(adjM, vis, i);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n+1, 0);
        int cnt = 0;
        for(int i = 0;i<n; i++){
            if(!vis[i]){
                cnt++;
                dfs(isConnected, vis, i);
            }
        }
        return cnt;
    }
};