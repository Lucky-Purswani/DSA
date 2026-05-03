class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int odd = 0;
        int even = 0;
        int n = nums.size();
        vector<pair<int, int>> v(n); //odd, even
        for(int i = n-1; i >= 0; i--){
            int y = nums[i];
            if(y % 2 == 0){
                v[i] = {odd, even};
                even++;
            }
            else{
                v[i] = {odd, even};
                odd++;
            }
        }
        vector<int> ans(n);
        for(int i = 0; i<n; i++){
            if(nums[i] % 2 == 0){
                ans[i] = v[i].first;
            }
            else{
                ans[i] = v[i].second;
            }
        }
        return ans;
    }
};