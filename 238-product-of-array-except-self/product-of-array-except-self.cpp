class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<long long> r(n);
        long long temp = 1;
        for(int i = n-1; i>=0; i--){
            r[i] = temp;
            temp *= nums[i];
        }

        for(auto &i:r){
            cout << i << " ";
        }


        temp = 1;
        cout << endl;
        vector<int> l(nums.begin(), nums.end());
        for(int i = 0; i<n; i++){
            cout << temp << " ";
            nums[i] = temp*r[i];
            temp *= l[i];
        }

        return nums;

        //  3, 2, 3, 4
        //r 24, 12 , 4 , 1  
        // var temp = 6
        //  24, 36, 
    }
};