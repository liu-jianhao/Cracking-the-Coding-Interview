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
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }

    bool helper(TreeNode* root, long lower, long upper) {
        if (root == nullptr) {
            return true;
        }
        if (root->val <= lower || root->val >= upper) {
            return false;
        }
        return helper(root->left, lower, root->val) && helper(root->right, root->val, upper);
    }
};


// 中序遍历
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> st;
        long inorder = LONG_MIN;

        while (!st.empty() || root != nullptr) {
            while (root != nullptr) {
                st.push(root);
                root = root->left;
            }

            root = st.top();
            st.pop();
            if (root->val <= inorder) {
                return false;
            }

            inorder = root->val;
            root = root->right;
        }

        return true;
    }
};