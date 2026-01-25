class Solution {
public:
    int minBitFlips(int start, int goal) {
        int cnt = 0;
        int xr = start ^ goal;
        while(xr){
            if((xr & 1) == 1) cnt++;
            xr = xr >> 1;
        }
        return cnt;
    }
};
