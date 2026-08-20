class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> a1;
        vector<int> a2;
        int n = nums.size();
        vector<int> ans;
        a1.push_back(nums[0]);
        a2.push_back(nums[1]);
        for(int i = 2; i<n; i++){
            if(a1.back() > a2.back()) a1.push_back(nums[i]);
            else a2.push_back(nums[i]);
        }

        for(auto &i:a1){
            ans.push_back(i);
        }
        for(auto &i:a2){
            ans.push_back(i);
        }
        return ans;
    }
};