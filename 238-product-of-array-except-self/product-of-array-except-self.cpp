class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        long long temp = 1;
        for(int i = 0; i<n; i++){
            ans[i] = temp;
            temp *= nums[i];
        }

        // for(auto &i:ans){
        //     cout << i << " ";
        // }


        temp = 1;
        // cout << endl;
        for(int i = n-1; i>=0; i--){
            // cout << temp << " ";
            ans[i] = temp*ans[i];
            temp *= nums[i];
        }

        return ans;
    }
};