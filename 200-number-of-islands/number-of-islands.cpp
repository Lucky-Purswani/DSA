class Solution {
public:
    void dfs(vector<vector<char>>& mat, int i, int j){
        if(mat[i][j] == '0') return;
        mat[i][j] = '0';

        if(i>=1) dfs(mat, i-1, j); //top
        if(j>=1) dfs(mat, i, j-1); //left
        if(i<mat.size()-1) dfs(mat, i+1, j); //bottom
        if(j<mat[0].size()-1) dfs(mat, i, j+1); //right
    }

    int numIslands(vector<vector<char>>& isConn) {
        int n = isConn.size();
        vector<vector<bool>> vis(n, vector<bool>(isConn[0].size(), false) );
        int ans = 0;
        for(int i = 0; i<isConn.size(); i++){
            for(int j = 0; j<isConn[0].size(); j++){
                if(isConn[i][j] == '1'){
                    dfs(isConn, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};