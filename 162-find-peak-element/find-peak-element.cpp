class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        int s = 0;
        int e = n - 1;

        while (s <= e) {
            int m = s + (e - s) / 2;

            bool left = (m == 0) || (nums[m] > nums[m - 1]);
            bool right = (m == n - 1) || (nums[m] > nums[m + 1]);

            if (left && right) {
                return m;
            }

            else if (m < n - 1 && nums[m] < nums[m + 1]) {
                s = m + 1;
            }

            else {
                e = m - 1;
            }
        }

        return -1;
    }
};