class Solution {
public:
    void solve(vector<int>& arr, vector<vector<int>> &ans, int i, vector<int> &curr) {
        if(i == arr.size()) {
            return ans.push_back(curr);
        }

        // exclude s[i]
        int next = i + 1;
        while(next < arr.size() && arr[next] == arr[i]) {
            next++;
        }
        solve(arr, ans, next, curr);

        // include s[i]
            curr.push_back(arr[i]);
            solve(arr, ans, i + 1, curr);
            curr.pop_back();
        
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(arr.begin(), arr.end());
        solve(arr, ans, 0, curr);
        return ans;
    }
};