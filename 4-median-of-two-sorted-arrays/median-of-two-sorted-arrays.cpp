class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int n1 = nums1.size();
        int n2 = nums2.size();
        int i = 0;
        int j = 0;
        while(i<n1 && j<n2){
            if(nums1[i] <= nums2[j]){
                ans.push_back(nums1[i]);
                i++;
            }
            else{
                ans.push_back(nums2[j]);
                j++;
            }
        }
        while(i < n1){
            ans.push_back(nums1[i]);
            i++;
        }
        while(j < n2){
            ans.push_back(nums2[j]);
            j++;
        }

        for(auto &i:ans){
            cout << i << " ";
        }

        if(ans.size() % 2 == 0){
            double med = ((double)ans[ans.size()/2] + ans[(ans.size()/2) - 1])/2;
            return med;
        }
        return ans[ans.size()/2];
    }
};