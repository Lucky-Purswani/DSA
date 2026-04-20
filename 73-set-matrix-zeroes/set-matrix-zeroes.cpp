class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        bool firstRowImpacted = false;
        bool firstColImpacted = false;

        // Check if first row has any zero
        for(int j = 0; j<n; j++){
            if(matrix[0][j] == 0){
                firstRowImpacted = true;
                break;
            } 
        }

        // Check if first column has any zero
        for(int i = 0; i<m; i++){
            if(matrix[i][0] == 0){
                firstColImpacted = true;
                break;
            } 
        }
        // Check if first row has any zero
//         for (int col = 0; col < n; col++) {
//             if (matrix[0][col] == 0) {
//                 firstRowImpacted = true;
//                 break;
//             }
//         }

//         // Check if first column has any zero
//         for (int row = 0; row < m; row++) {
//             if (matrix[row][0] == 0) {
//                 firstColImpacted = true;
//                 break;
//             }
//         }

        // Set markers in first row and first column
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Set zeroes using markers
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Handle first row
        if (firstRowImpacted) {
            for (int col = 0; col < n; col++) {
                matrix[0][col] = 0;
            }
        }

        // Handle first column
        if (firstColImpacted) {
            for (int row = 0; row < m; row++) {
                matrix[row][0] = 0;
            }
        }
    }
};
// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//         int m = matrix.size();
//         int n = matrix[0].size();

//         bool firstRowImpacted = false;
//         bool firstColImpacted = false;

//         // Check if first row has any zero
//         for (int col = 0; col < n; col++) {
//             if (matrix[0][col] == 0) {
//                 firstRowImpacted = true;
//                 break;
//             }
//         }

//         // Check if first column has any zero
//         for (int row = 0; row < m; row++) {
//             if (matrix[row][0] == 0) {
//                 firstColImpacted = true;
//                 break;
//             }
//         }

//         // Set markers in first row and first column
//         for (int i = 1; i < m; i++) {
//             for (int j = 1; j < n; j++) {
//                 if (matrix[i][j] == 0) {
//                     matrix[i][0] = 0;
//                     matrix[0][j] = 0;
//                 }
//             }
//         }

//         // Set zeroes using markers
//         for (int i = 1; i < m; i++) {
//             for (int j = 1; j < n; j++) {
//                 if (matrix[i][0] == 0 || matrix[0][j] == 0) {
//                     matrix[i][j] = 0;
//                 }
//             }
//         }

//         // Handle first row
//         if (firstRowImpacted) {
//             for (int col = 0; col < n; col++) {
//                 matrix[0][col] = 0;
//             }
//         }

//         // Handle first column
//         if (firstColImpacted) {
//             for (int row = 0; row < m; row++) {
//                 matrix[row][0] = 0;
//             }
//         }
//     }
// };