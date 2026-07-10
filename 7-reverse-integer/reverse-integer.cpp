class Solution {
public:

    int helper(long long x, long long sum)
    {
        if(x == 0)
        {
            if(sum > INT_MAX || sum < INT_MIN)
                return 0;

            return sum;
        }

        return helper(x/10, sum*10 + x%10);
    }


    int reverse(int x) 
    {
        return helper(x,0);
    }
};