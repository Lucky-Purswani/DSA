class Solution {
public:
    void dfs(int n, vector<vector<int>>& adjL, vector<bool> &vis) {
        vis[n] = true;
        for(int i = 0;i<adjL[n].size(); i++){
            if(!vis[adjL[n][i]]){
                dfs(adjL[n][i], adjL, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>> adjL(isConnected.size()+1);
        for(int i = 0; i<isConnected.size(); i++){
            for(int j = 0; j<isConnected[0].size(); j++){
                if(isConnected[i][j] == 1){
                    adjL[i+1].push_back(j+1);
                }
            }
        }
        vector<bool> vis(isConnected.size()+1, false);
        int ans = 0;
        for(int i = 1;i<vis.size(); i++){
            if(!vis[i]){
                dfs(i, adjL, vis);
                ans++;
            }
        }
        return ans;
    }
};