/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 func getIntersectionNode(headA, headB *ListNode) *ListNode {
    pA, pB := headA, headB
    for pA != pB {
        if pA != nil {
            pA = pA.Next
        } else {
            pA = headB
        }
    
        if pB != nil {
            pB = pB.Next
        } else {
            pB = headA
        }
    }

    return pA
}