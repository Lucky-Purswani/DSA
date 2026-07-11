class Solution {
public:
    int numberOfSteps(int num) {
        if(num == 0) return 0;
        if(num % 2 == 1) num--;
        else num /= 2;
        return 1+numberOfSteps(num);
    }
};