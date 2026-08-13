class DisjointSet {
    vector<int> rank, parent, size;
    
    public:
        DisjointSet(int n){
            rank.resize(n+1, 0);
            parent.resize(n+1, 0);
            size.resize(n+1, 0);
            for(int i = 0; i<=n; i++){
                parent[i] = i;
                size[i] = 1;
            }
        }
        
        int findPar(int node){
            if(parent[node] == node) return node;
            
            return parent[node] = findPar(parent[node]); // this is for relinking so that every node points to its ultimate parent.
        }
        
        void unionByRank(int u, int v){
            int ulp_u = findPar(u);
            int ulp_v = findPar(v);
            if(ulp_u == ulp_v) return;
            
            if(rank[ulp_u] > rank[ulp_v]){
                parent[ulp_v] = ulp_u;
            }
            else if(rank[ulp_u] < rank[ulp_v]){
                parent[ulp_u] = ulp_v;
            }
            else{
                parent[ulp_u] = ulp_v;
                rank[ulp_v]++;
            }
        }
        
        void unionBySize(int u, int v){
            int ulp_u = findPar(u);
            int ulp_v = findPar(v);
            if(ulp_u == ulp_v) return;
            
            if(size[ulp_u] > size[ulp_v]){
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
            else{
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
        }
        
};

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


        //Disjoint set approach
        // DisjointSet ds(n);
        // for(int i = 0; i < n; i++) {
        //     for(int j = i + 1; j < n; j++) {
        //         if(isConnected[i][j] == 1) {
        //             ds.unionBySize(i, j);
        //         }
        //     }
        // }
        // int ans = 0;
        // for(int i = 0; i<n; i++){
        //     if(ds.findPar(i) == i) ans++;
        // }
        return cnt;
    }
};