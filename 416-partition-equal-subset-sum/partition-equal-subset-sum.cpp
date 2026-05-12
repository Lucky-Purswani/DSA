class Solution {
public:

    bool isValid(vector<int>& nums, long long sum, long long currSum, int i, vector<vector<int>> &dp){

        if(i < 0) return (currSum == sum/2);

        if(currSum == sum/2) return true;

        if(dp[i][currSum] != -1) return dp[i][currSum];

        bool p = isValid(nums, sum, currSum + nums[i], i - 1, dp);

        bool np = isValid(nums, sum, currSum, i - 1, dp);

        return dp[i][currSum] = p || np;
    }

    bool canPartition(vector<int>& nums) {

        long long sum = 0;

        for(auto &i : nums){
            sum += i;
        }

        if(sum % 2) return false;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        return isValid(nums, sum, 0, nums.size() - 1, dp);
    }
};