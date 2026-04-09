class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i = 0;
        int n = nums.size();

        // Cyclic Sort
        while (i < n) {
            int corr = nums[i] - 1;
            if (nums[i] != nums[corr]) {
                swap(nums[i], nums[corr]);
            } else {
                i++;
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return nums[i];
            }
        }
        return -1;
    }
};