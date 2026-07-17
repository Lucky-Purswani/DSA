class Solution {
public:
    bool judgeSquareSum(int c) {
        // cout << c << " " << endl;
        int rt = sqrt(c);
        // cout << c << " " << rt;
        if(rt*rt == c) return true;
        int i = 0;
        int j = rt;

        while(i <= j){
            long long a2 = i*i;
            long long b2 = j*j;

            if(a2+b2 == c) return true;
            if(a2+b2 < c) i++;
            if(a2+b2 > c) j--;
        }


        return false;
    }
};