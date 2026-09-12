class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        // 1 2 3 4 -> cyclic rotate by 2 ele on prefix
        // 1 2 & 3 4
        // 2 1 & 4 3 -> rev
        // 3 4 1 2 -> join and then rev.

        // 1 2 3 4 ls = 3, rs = 7 -> targets are 1, 3
        // 2 3 4 1 ls = 5, rs = 5 -> targets are 2, 4
        // 3 4 1 2 ls = 7, rs = 3 -> targets are 3, 1
        // 4 1 2 3 ls = 5, rs = 5 -> targets are 4, 2

        // 10 6 ls = 10, rs = 6 ans = 1;
        // 6 10 ls = 6, rs = 10 ans = 1;


        long long ls = 0;
        long long rs = 0;
        int ans = 0;

        // 1st iteration
        int n = nums.size();
        int i = 0, j = n/2;

        for(int i = 0; i<n; i++){
            if(i<n/2){
                ls += nums[i];
            }
            else{
                rs += nums[i];
            }
        }

        // if(ls > rs) ans++;

        cout << ls << " " << rs << endl;

        while(j<n){
            ls += nums[j];
            rs += nums[i];

            rs -= nums[j];
            ls -= nums[i];
            if(ls > rs) ans++;
            cout << ls << " " << rs << endl;
            j++;
            i++;
        }
        i = 0, j = n/2;
        while(j<n){
            rs += nums[j];
            ls += nums[i];

            ls -= nums[j];
            rs -= nums[i];
            if(ls > rs) ans++;
            cout << ls << " " << rs << endl;

            j++;
            i++;
        }

        return ans;
    }
};