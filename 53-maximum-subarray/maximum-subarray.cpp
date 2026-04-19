class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int best = nums[0];
        for(int i = 1; i<nums.size(); i++){
            int v1 = nums[i];
            int v2 = nums[i]+best;
            best = max(v1, v2);
            ans = max(ans, best);
            
        }
        return ans;
    }
};
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int ans = INT_MIN;
//         int sum = 0;
//         for(int i = 0; i<nums.size(); i++){
//             sum += nums[i];
//             ans = max(ans, sum);
//             if(sum < 0) sum = 0;
//         }
//         return ans;
//     }
// };