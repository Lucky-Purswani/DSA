class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> v;
        for(auto &i : nums){
            vector<int> ans;
            while(i > 0){
                ans.push_back(i % 10);
                i /= 10;
            }
            reverse(ans.begin(), ans.end());
            v.insert(v.end(), ans.begin(), ans.end());
        }
        return v;
    }
};