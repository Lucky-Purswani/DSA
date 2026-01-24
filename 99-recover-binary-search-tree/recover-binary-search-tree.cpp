// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     TreeNode* findInorderPredecessor(TreeNode* curr){
//         auto temp = curr->left;
//         while(temp->right && temp->right != curr){
//             temp = temp->right;
//         }
//         return temp;
//     }
//     void recoverTree(TreeNode* root) {
//         TreeNode* first = NULL;
//         TreeNode* second = NULL;
//         TreeNode* prev = NULL;
//         auto curr = root;
//         while(curr){
//             if(curr->left == NULL){

//                 //Do something
//                 if(prev && curr->val < prev->val && !first && !second){
//                     first = prev;
//                     second = curr;
//                 }
//                 else if(prev && curr->val < prev->val && first && second){
//                     second = curr;
//                 }
//                 prev = curr;
                
//                 curr = curr->right;
//             }
//             else{
//                 auto IP = findInorderPredecessor(curr);
//                 if(IP->right == NULL){
//                     IP->right = curr;
//                     curr = curr->left;
//                 }
//                 else{
//                     IP->right = NULL;

//                     //Do something
//                     if(prev && curr->val < prev->val && !first && !second){
//                         first = prev;
//                         second = curr;
//                     }
//                     else if(prev && curr->val < prev->val && first && second){
//                         second = curr;
//                     }
//                     prev = curr;

//                     curr = curr->right;
//                 }
//             }
//         }
//         if(first && second) swap(first->val, second->val);
//     }
// };

// class Solution {
// public:
//     void inorder(TreeNode* root, vector<TreeNode*>& ans) {
//         if (!root) return;
//         inorder(root->left, ans);
//         ans.push_back(root);
//         inorder(root->right, ans);
//     }

//     void recoverTree(TreeNode* root) {
//         vector<TreeNode*> ans;
//         inorder(root, ans);

//         TreeNode* first = nullptr;
//         TreeNode* second = nullptr;

//         for (int i = 0; i < ans.size() - 1; i++) {
//             if (ans[i]->val > ans[i + 1]->val) {
//                 if (!first) {
//                     first = ans[i];
//                     second = ans[i + 1];
//                 } else {
//                     second = ans[i + 1];
//                 }
//             }
//         }

//         swap(first->val, second->val);
//     }
// };

class Solution {
public:
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = nullptr;

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);

        // detect violation
        if (prev && root->val < prev->val) {
            if (!first) {
                first = prev;
                second = root;
            } else {
                second = root;
            }
        }

        prev = root;

        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        inorder(root);
        if(first&&second) swap(first->val, second->val);
    }
};
