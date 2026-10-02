class Solution {
public:
    int maxSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        int ans = 0;

        unordered_map<long long, int> mp;

        while (j < n) {
            bool bad = false;
            long long cur = nums[j];

            for (auto &[x, cnt] : mp) {

                // cur + x = z
                if (mp.count(cur + x)) {
                    bad = true;
                    break;
                }

                // x + y = cur
                long long y = cur - x;

                if (mp.count(y)) {
                    if (y != x || cnt >= 2) {
                        bad = true;
                        break;
                    }
                }
            }

            if (!bad) {
                mp[cur]++;
                ans = max(ans, j - i + 1);
                j++;
            }
            else {
                mp[nums[i]]--;

                if (mp[nums[i]] == 0)
                    mp.erase(nums[i]);

                i++;
            }
        }

        return ans;
    }
};