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
    int makeConnected(int n, vector<vector<int>>& connections) {
        // Disjoint set approach
        DisjointSet ds(n);
        int wire = 0;
        for(int i = 0; i < connections.size(); i++) {
            int u = connections[i][0];
            int v = connections[i][1];
            if(ds.findPar(u) != ds.findPar(v)){
                ds.unionBySize(u, v);
            }
            else{
                wire++;
            }
        }
        int ans = 0;
        for(int i = 0; i<n; i++){
            if(ds.findPar(i) == i) ans++;
        }

        if(ans-wire <= 1) return ans-1;

        return -1;
    }
};