class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int D) {
        int n = nums.size();
        int R = 0;
        for(auto &i : nums){
            R += i;
        }
        if((R < abs(D)) || ((R + D) % 2 == 1)) return 0;
        int target = (R+D)/2;
        vector<int> prev(target + 1, 0);
        vector<int> curr(target + 1, 0);
        prev[0] = 1;
        for(int i = 1; i<=n; i++){
            curr[0] = 1;
            for(int j = 0; j<=target; j++){
                int np = prev[j];
                int p = 0;
                if(j >= nums[i-1]){
                    p = prev[j-nums[i-1]];
                }
                curr[j] = np + p;
            }
            prev = curr;
        }
        return prev[target];
    }
};