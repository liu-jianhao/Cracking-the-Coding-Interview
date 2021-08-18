/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 快慢指针
class Solution {
public:
    int kthToLast(ListNode* head, int k) {
        auto slow = head;
        auto fast = head;

        while (k--) {
            fast = fast->next;
        }

        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow->val;
    }
};


// 栈
class Solution {
public:
    int kthToLast(ListNode* head, int k) {
        std::stack<int> s;

        auto cur = head;
        while (cur != nullptr) {
            s.push(cur->val);
            cur = cur->next;
        }

        while (--k) {
            s.pop();
        }

        return s.top();
    }
};