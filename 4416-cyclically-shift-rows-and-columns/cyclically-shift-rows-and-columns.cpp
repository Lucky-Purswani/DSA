class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid,
                                    vector<int>& rowShift,
                                    vector<int>& colShift) {
        vector<vector<int>> ans(n, vector<int>(n, 0));

        // Row shifts
        for(int i = 0; i < n; i++){
            int rs = rowShift[i] % n;
            int j = 0;

            while(j < n){
                ans[i][j] = grid[i][rs % n];
                rs++;
                j++;
            }
        }

        // Column shifts
        for(int j = 0; j < n; j++){
            int cs = colShift[j] % n;
            int i = 0;

            while(i < n){
                grid[i][j] = ans[cs % n][j];
                cs++;
                i++;
            }
        }

        return grid;
    }
};