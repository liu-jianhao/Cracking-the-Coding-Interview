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
    TreeNode* dfs(const vector<int> &nums, int L, int R) {
        if(L > R) {
            return nullptr;
        }
        int mid = (L+R)>>1;
        auto ptr = new TreeNode(nums[mid]);
        ptr->left = dfs(nums, L, mid-1);
        ptr->right = dfs(nums, mid+1, R);
        return ptr;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(nums, 0, nums.size()-1);
    }
};