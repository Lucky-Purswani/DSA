class Solution {
public:
    int maxProduct(int n) {
        int prod = 1;
        int temp = n;
        int mx1 = 0;
        int mx2 = 0;
        while(temp){
            int x = temp%10;
            if (x > mx1) {
                mx2 = mx1;
                mx1 = x;
            } 
            else if (x > mx2) {
                mx2 = x;
            }
            temp/=10;
        }
        return mx1*mx2;
    }
};