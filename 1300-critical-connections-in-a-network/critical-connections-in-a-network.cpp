class Solution {
public:
    int timer = 1;
    void dfs(vector<vector<int>> &adj, vector<vector<int>> &bridges, vector<int> &vis, vector<int> &t, vector<int> &low, int node, int parent){
        vis[node] = 1;
        t[node] = low[node] = timer++;
        for(auto &i:adj[node]){
            if(i == parent) continue;
            if(!vis[i]){
                dfs(adj, bridges, vis, t, low, i, node);
                low[node] = min(low[node], low[i]);
                if(low[i] > t[node]){
                    bridges.push_back({node, i});
                }
            }
            else{
                low[node] = min(low[node], low[i]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        vector<vector<int>> bridges;
        for(auto &i:connections){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        vector<int> vis(n, 0);
        vector<int> t(n);
        vector<int> low(n);

        dfs(adj, bridges, vis, t, low, 0, -1);
        return bridges;
    }
};