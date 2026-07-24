class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int> seen;

        // Store XOR of every pair (i <= j)
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                seen.insert(nums[i] ^ nums[j]);
            }
        }

        unordered_set<int> res;

        // XOR each number with every pair XOR
        for (int i = 0; i < n; i++) {
            for (int x : seen) {
                res.insert(nums[i] ^ x);
            }
        }

        return res.size();
    }
};