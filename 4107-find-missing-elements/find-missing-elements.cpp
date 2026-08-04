class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int s = INT_MAX;
        int e = INT_MIN;
        unordered_map<int, int> mp;
        for(auto &i:nums){
            mp[i]++;
            s = min(s, i);
            e = max(e, i);
        }

        if(s == INT_MAX || e == INT_MIN || s == e) return {};

        vector<int> ans;
        for(int i = s; i<=e; i++){
            if(!mp.count(i)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};