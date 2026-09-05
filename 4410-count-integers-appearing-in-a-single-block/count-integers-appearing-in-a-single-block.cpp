class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, int> mp;
        mp[nums[0]]++;
        for(int i = 1; i<nums.size(); i++){
            if(mp.count(nums[i])){
                if(nums[i] == nums[i-1]){
                    mp[nums[i]]++;
                    continue;
                }
                else{
                    mp[nums[i]] = -1000;
                }
            }
            else{
                mp[nums[i]]++;
            }
        }
        int ans = 0;
        for(auto &i:nums){
            mp[i]--;
            if(mp[i] == 0) ans++;
        }

        return ans;

    }
};