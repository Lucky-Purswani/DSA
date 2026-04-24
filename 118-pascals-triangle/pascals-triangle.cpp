class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        for(int i = 1; i<=n; i++){
            vector<int> temp;
            int res = 1;
            int num = i-1;
            temp.push_back(res);
            for(int j = 1; j<i; j++){
                res *= num;
                res /= j;
                num--;
                temp.push_back(res);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};