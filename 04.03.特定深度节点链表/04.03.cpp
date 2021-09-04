/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> listOfDepth(TreeNode* tree) {
        vector<ListNode*> res;
        if(tree == nullptr) {
            return res;
        }

        queue<TreeNode*> q;
        q.push(tree);

        while(!q.empty()) {
            ListNode* head = nullptr;
            ListNode* prev = nullptr;

            int size = q.size();
            for(int i = 0; i < size; ++i) {
                TreeNode* cur = q.front();
                q.pop();
                ListNode* node = new ListNode(cur->val);

                if(head == nullptr) {
                    head = node;
                } else {
                    prev->next = node;
                }
                prev = node;

                if(cur->left != nullptr) {
                    q.push(cur->left);
                }
                if(cur->right != nullptr) {
                    q.push(cur->right);
                }
            }
            
            res.push_back(head);
        }

        return res;
    }
};