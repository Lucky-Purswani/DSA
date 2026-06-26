class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        pair<int, int> temp;
        temp.first = intervals[0][0];
        temp.second = intervals[0][1];
        for(int i = 1; i<intervals.size(); i++){
            if(intervals[i][0] <= temp.second){
                temp.second = max(intervals[i][1], temp.second);
            }
            else{
                ans.push_back({temp.first, temp.second});
                temp.first = intervals[i][0];
                temp.second = intervals[i][1];
            }
        }
        ans.push_back({temp.first, temp.second});
        return ans;

    }
};