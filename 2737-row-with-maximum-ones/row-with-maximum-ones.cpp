class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {

        int mx = 0;
        int row = 0;

        for(int i = 0; i < mat.size(); i++){

            int cnt = 0;

            for(auto &j : mat[i]){
                cnt += j;
            }

            if(cnt > mx){
                mx = cnt;
                row = i;
            }
        }

        return {row, mx};
    }
};