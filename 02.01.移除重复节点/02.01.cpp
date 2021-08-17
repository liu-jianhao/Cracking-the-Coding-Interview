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
    ListNode* removeDuplicateNodes(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }

        std::unordered_set<int> set;
        set.insert(head->val);

        auto pos = head;
        while (pos->next != nullptr) {
            auto cur = pos->next;
            if (set.count(cur->val)) {
                pos->next = pos->next->next;
            } else {
                set.insert(cur->val);
                pos = pos->next;
            }
        }

        return head;
    }
};