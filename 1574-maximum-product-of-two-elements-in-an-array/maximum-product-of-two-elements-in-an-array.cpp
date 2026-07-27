class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx = INT_MIN;
        int secondMx = INT_MIN;

        for (int x : nums) {
            if (x > mx) {
                secondMx = mx;
                mx = x;
            } 
            else if (x > secondMx) {
                secondMx = x;
            }
        }

        return (secondMx-1)*(mx-1);
    }
};