class Solution {
public:
    int sumDigits(int num){
        if(num == 0) return 0;
        return num%10 + addDigits(num/10);
    }
    int addDigits(int num) {
        while(num >= 10){
            num = sumDigits(num);
        }
        return num;
    }
};