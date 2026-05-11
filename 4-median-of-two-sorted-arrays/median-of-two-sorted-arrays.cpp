class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int i = 0, j = 0, count = 0;
        int n1 = a.size(), n2 = b.size(), n = n1 + n2;
        int index1 = n / 2, index2 = (n % 2 == 0) ? index1 - 1 : -1;
        int index1el = -1, index2el = -1;

        while (i < n1 && j < n2) {
            int val;
            if(a[i] < b[j]){
                val = a[i];
                i++;
            }
            else{
                val = b[j];
                j++;
            }
            if(count == index1) index1el = val;
            if(count == index2) index2el = val;
            count++;
        }

        while (i < n1) {
            int val = a[i];
            i++;
            if(count == index1) index1el = val;
            if(count == index2) index2el = val;
            count++;
        }

        while (j < n2) {
            int val = b[j];
            j++;
            if(count == index1) index1el = val;
            if(count == index2) index2el = val;
            count++;
        }

        return (n % 2 == 0) ? (double(index1el + index2el) / 2) : index1el;
    }
};
