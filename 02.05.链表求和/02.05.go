/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    res := &ListNode{}
    l1Cur, l2Cur := l1, l2
    resCur := res
    carry := 0
    for l1Cur != nil || l2Cur != nil || carry > 0 {
        sum := 0
        if l1Cur != nil {
            sum += l1Cur.Val
            l1Cur = l1Cur.Next
        }
        if l2Cur != nil {
            sum += l2Cur.Val
            l2Cur = l2Cur.Next
        }
        sum += carry
        
        carry = sum / 10
        sum = sum % 10
        resCur.Next = &ListNode{
            Val: sum,
        }
        resCur = resCur.Next
    }

    return res.Next
}