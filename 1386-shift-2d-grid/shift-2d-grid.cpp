class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        int last = n*m;
        int ele = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                int temp = (ele + k)%last;
                int r = temp / m;
                int c = temp % m;
                ans[r][c] = grid[i][j];
                ele++;
            }
        }
        return ans;
    }
};