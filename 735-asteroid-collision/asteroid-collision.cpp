class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> result;
        for(int &i : asteroids){
            //Collision will occurs
            while(!result.empty() && i<0 && result.back() > 0){
                int sum = i + result.back();
                if(sum > 0){
                    i=0;
                }
                else if(sum < 0){
                    result.pop_back();
                }
                else{
                    result.pop_back();
                    i = 0;
                }
            }
            //No collision
            if(i!=0) result.push_back(i);
        }
        return result;
    }
};