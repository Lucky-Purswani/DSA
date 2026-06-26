class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        unordered_map<int, int> mp;
        for(auto &i: nums){
            mp[i]++;
        }
        for(auto &i : mp){
            pq.push({i.second, i.first});
            if(pq.size() > k){
                pq.pop();
            }
        }
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         vector<int> ans;
//         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//         unordered_map<int, int> mp;
//         for(int i = 0; i<nums.size(); i++){
//             if(mp.find(nums[i]) != mp.end()){
//                 mp[nums[i]]++;
//             }
//             else{
//                 mp[nums[i]] = 1;
//             }
//         }
//         for(auto& i : mp){
//             pq.push({i.second, i.first});
//             if(pq.size() > k) pq.pop();
//         }
//         while(!pq.empty()){
//             ans.emplace_back(pq.top().second);
//             pq.pop();
//         }
//         return ans;
//     }
// };