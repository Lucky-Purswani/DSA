class Solution {
public:
    vector<int> solve(vector<vector<char>>& grid, vector<vector<int>>& vis, int i, int j) {
        int n = grid.size();
        int m = grid[0].size();

        vis[i][j] = 1;

        int x = i, y = j;

        if (grid[i][j] == 'L') y--;
        else if (grid[i][j] == 'U') x--;
        else if (grid[i][j] == 'R') y++;
        else x++;

        if (x < 0 || y < 0 || x >= n || y >= m || vis[x][y]) {
            return {i, j};
        }

        return solve(grid, vis, x, y);
    }

    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        return solve(grid, vis, 0, 0);
    }
};