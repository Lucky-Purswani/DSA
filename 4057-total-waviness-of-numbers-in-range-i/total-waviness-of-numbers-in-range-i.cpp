class Solution {
public:
    int pv(int num){
        vector<int> dig;
        int t = num;
        while(t > 0){
            dig.push_back(t%10);
            t /= 10;
        }
        int n = dig.size();
        int cnt = 0;
        for(int i = 1; i<n-1; i++){
            if(dig[i] > dig[i-1] && dig[i] > dig[i+1]){
                cnt++;
            }
            if(dig[i] < dig[i-1] && dig[i] < dig[i+1]){
                cnt++;
            }
        }
        return cnt;
    }
    int totalWaviness(int num1, int num2) {
        int ans = 0;
        for(int i = num1; i<=num2; i++){
            ans += pv(i);
        }
        return ans;
    }
};