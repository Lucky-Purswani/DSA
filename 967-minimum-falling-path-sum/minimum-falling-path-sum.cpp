class Solution {
public:
    const int INF = 1e9;
    int solve(vector<vector<int>>& grid, int i, int j,
              vector<vector<int>>& dp) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
            return INT_MAX;

        if (i == grid.size() - 1)
            return grid[i][j];

        if (dp[i][j] != INF)
            return dp[i][j];

        int ld = INT_MAX, down = INT_MAX, rd = INT_MAX;

        // Left Diagonal
        if (j - 1 >= 0) {
            int x = solve(grid, i + 1, j - 1, dp);
            if (x != INT_MAX)
                ld = grid[i][j] + x;
        }

        // Down
        {
            int x = solve(grid, i + 1, j, dp);
            if (x != INT_MAX)
                down = grid[i][j] + x;
        }

        // Right Diagonal
        if (j + 1 < grid[0].size()) {
            int x = solve(grid, i + 1, j + 1, dp);
            if (x != INT_MAX)
                rd = grid[i][j] + x;
        }

        return dp[i][j] = min({ld, down, rd});
    }

    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INF));

        int ans = INT_MAX;
        for (int j = 0; j < m; j++) {
            ans = min(ans, solve(grid, 0, j, dp));
        }

        return ans;
    }
};