class Solution {
public:
    int sm(int n){
        int sum = 0;
        while(n){
            sum += n%10;
            n/=10;
        }
        return sum;
    }
    int largestInteger(int n, int s) {
        int num = 0;
        int pow = 1;
        while(n){
            num = 10*pow - 1;
            pow *= 10;
            n--;
        }
        int ans = -1;
        for(int i = 0; i<=num; i++){
            if(sm(i) == s){
                ans = i;
            }
        }
        return ans;
    }
};