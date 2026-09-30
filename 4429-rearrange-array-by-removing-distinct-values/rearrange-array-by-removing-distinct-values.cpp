class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        map<int, int> mp;

        for(auto &i:nums){
            mp[i]++;
        }

        vector<int> ans;

        while(!mp.empty()){
            for(auto &p:mp){
                int key = p.first;
                int freq = p.second;

                ans.push_back(key);
                mp[key]--;
            }

            for(auto it = mp.begin(); it != mp.end(); ){
                if(it->second == 0){
                    it = mp.erase(it);
                }
                else{
                    it++;
                }
            }
        }

        return ans;
    }
};