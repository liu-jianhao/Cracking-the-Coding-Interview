/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (p->right) {
            p = p->right;
            while (p->left) {
                p = p->left;
            }
            return p;
        }
        TreeNode* res = nullptr;
        while (root != p) {
            if (root->val < p->val) {
                root = root->right;
            } else {
                res = root;
                root = root->left;
            }
        }
        return res;
    }
};