class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n);
        int mx = INT_MIN;
        for(int i = n-1; i>=0; i--){
            mx = max(nums[i], mx);
            v[i] = mx;
        }
        int ans = 0;
        for(int i = 0; i<n; i++){
            ans = max(ans, v[i]-nums[i]);
        }
        return ans;
    }
};