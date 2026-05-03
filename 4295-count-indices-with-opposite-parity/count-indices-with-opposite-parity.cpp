class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int odd = 0, even = 0;
        int n = nums.size();
        vector<int> ans(n);

        for(int i = n - 1; i >= 0; i--){
            if(nums[i] % 2 == 0){
                ans[i] = odd;   // need opposite → odd
                even++;
            } else {
                ans[i] = even;  // need opposite → even
                odd++;
            }
        }
        return ans;
    }
};