// Using Bit manipulation
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int subs = 1<<nums.size();
        vector<vector<int >> ans;
        for(int n = 0; n<subs ; n++){
            vector<int> subset;
            for(int i = 0; i<nums.size(); i++){
                if(n & 1<<i) subset.emplace_back(nums[i]);
            }
            ans.emplace_back(subset);
        }
        return ans;
    }
};


//Using recurrsion.
// class Solution {
// private:
//     void solve(int index, vector<int> output, vector<vector<int >> &ans, vector<int> nums){
//         int n = nums.size();
//         if(index >= n){
//             ans.emplace_back(output);
//             return;
//         }

//         //Exclude or dont add this curr element.
//         solve(index+1, output, ans, nums);

//         //Include the element and go to next.
//         output.emplace_back(nums[index]);
//         solve(index+1, output, ans, nums);

//     }

// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<vector<int >> ans;
//         vector<int> output;
//         int index = 0;
//         solve(index, output, ans, nums);
        
//         return ans;
//     }
// };