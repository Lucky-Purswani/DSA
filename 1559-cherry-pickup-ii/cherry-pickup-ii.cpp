class Solution {
public:
    int solve(vector<vector<int>>& grid, int i, int j1, int j2, vector<vector<vector<int>>> &dp) {
        int rows = grid.size(), cols = grid[0].size();

        if (j1 < 0 || j1 >= cols || j2 < 0 || j2 >= cols) return -1e9;

        if(i == grid.size()-1){
            if(j1 == j2) return grid[i][j1];
            return grid[i][j1] + grid[i][j2];
        }

        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

        int val = grid[i][j1] + (j1 != j2 ? grid[i][j2] : 0);
        int ans = -1e9;
        for (int d1 = -1; d1 <= 1; d1++) {
            for (int d2 = -1; d2 <= 1; d2++) {
                int path = val + solve(grid, i + 1, j1 + d1, j2 + d2, dp);
                ans = max(ans, path);
            }
        }

        return dp[i][j1][j2] = ans;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<vector<int>>> dp(rows, 
                                        vector<vector<int>>(cols, 
                                        vector<int>(cols, -1)));
        return solve(grid, 0, 0, grid[0].size() - 1, dp);
    }
};