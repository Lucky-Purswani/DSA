class Solution {
public:
    int n;
    int solve(vector<vector<int>>& grid, int steps, int r1, int r2, vector<vector<vector<int>>>& dp) {
        int c1 = steps - r1, c2 = steps - r2;

        if (r1 < 0 || r1 >= n || r2 < 0 || r2 >= n || c1 < 0 || c1 >= n || c2 < 0 || c2 >= n)
            return -1e9;
        if (grid[r1][c1] == -1 || grid[r2][c2] == -1)
            return -1e9;

        if (steps == 2 * n - 2)
            return grid[r1][c1]; // both at (n-1, n-1)

        if (dp[steps][r1][r2] != -1) return dp[steps][r1][r2];

        int val = grid[r1][c1] + (r1 != r2 ? grid[r2][c2] : 0);

        int ans = -1e9;
        for (int d1 = 0; d1 <= 1; d1++) {
            for (int d2 = 0; d2 <= 1; d2++) {
                int path = val + solve(grid, steps + 1, r1 + d1, r2 + d2, dp);
                ans = max(ans, path);
            }
        }

        return dp[steps][r1][r2] = ans;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<vector<int>>> dp(2*n-1, vector<vector<int>>(rows, vector<int>(rows, -1)));
        int result = solve(grid, 0, 0, 0, dp);
        return max(result, 0);
    }
};