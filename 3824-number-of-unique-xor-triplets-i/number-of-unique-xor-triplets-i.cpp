class Solution {
public:
    vector<vector<vector<int>>> dp;

    void solve(vector<int> &nums, int i, int j, int k,
               unordered_map<int, int> &mp) {

        int n = nums.size();

        if (i == n || j == n || k == n)
            return;

        if (dp[i][j][k] != -1)
            return;

        dp[i][j][k] = 1;

        mp[nums[i] ^ nums[j] ^ nums[k]]++;

        solve(nums, i + 1, j, k, mp);
        solve(nums, i, j + 1, k, mp);
        solve(nums, i, j, k + 1, mp);
    }

    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return 1;
        if (n == 2) return 2;

        int ans = 1;
        while (ans <= n) ans <<= 1;
        return ans;
    }
};