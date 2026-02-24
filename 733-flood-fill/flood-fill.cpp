class Solution {
  public:
    void dfs(vector<vector<int>>& mat, int i, int j, int nc, int currColor){
        if(mat[i][j] != currColor || mat[i][j] == nc) return;
        mat[i][j] = nc;

        if(i>=1) dfs(mat, i-1, j, nc, currColor); //top
        if(j>=1) dfs(mat, i, j-1, nc, currColor); //left
        if(i<mat.size()-1) dfs(mat, i+1, j, nc, currColor); //bottom
        if(j<mat[0].size()-1) dfs(mat, i, j+1, nc, currColor); //right
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // code here
        // if(image[sr][sc] == newColor) return image;
        dfs(image, sr, sc, newColor, image[sr][sc]);
        return image;
    }
};