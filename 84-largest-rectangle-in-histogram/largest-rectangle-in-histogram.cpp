class Solution {
public:
    //Next smaller element
    vector<int> nextSmallerEle(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> ans(n, -1);
        int i = n-1;
        for(i; i>=0; i--){
            if(st.empty()){
                ans[i] = n;
                st.push(i);
            }
            else{
                while(!st.empty() && nums[st.top()] >= nums[i]){
                    st.pop();
                }
                if(st.empty()){
                    ans[i] = n;
                }
                else{
                    ans[i] = st.top();
                }
                st.push(i);
            }
        }
        return ans;
    }
    vector<int> prevSmaller(vector<int>& nums) {
        //  code here
        stack<int> st;
        int n = nums.size();
        vector<int> ans(n, -1);
        int i = 0;
        for(i; i<n; i++){
            if(st.empty()){
                ans[i] = -1;
                st.push(i);
            }
            else{
                while(!st.empty() && nums[st.top()] >= nums[i]){
                    st.pop();
                }
                if(st.empty()){
                    ans[i] = -1;
                }
                else{
                    ans[i] = st.top();
                }
                st.push(i);
            }
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nse = nextSmallerEle(heights);
        vector<int> pse = prevSmaller(heights);
        int mx = INT_MIN;
        for(int i = 0; i<n; i++){
            int w = nse[i] - pse[i] - 1;
            int h = heights[i];
            mx = max(mx, w*h);
        }
        return mx;
    }
};
// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         stack<int> st;
//         int maxArea = 0;
//         for(int i=0; i<heights.size(); i++){
//             while(!st.empty() && heights[st.top()] > heights[i]){
//                 int element = st.top(); //On which the opertaion is going to be taken out.
//                 st.pop();
//                 int pse = st.empty() ? -1 : st.top();
//                 maxArea = max(maxArea, heights[element]*(i-pse-1));
//             }
//             st.push(i);
//         }
//         while(!st.empty()){
//             int element = st.top();
//             st.pop();
//             int nse = heights.size();
//             int pse = st.empty() ? -1 : st.top();
//             maxArea = max(maxArea, heights[element]*(nse-pse-1));
//         }
//         return maxArea;
//     }
// };