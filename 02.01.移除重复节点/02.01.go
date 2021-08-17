/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 func removeDuplicateNodes(head *ListNode) *ListNode {
    if head == nil {
        return nil
    }

    m := make(map[int]bool)
    m[head.Val] = true

    pos := head
    for pos.Next != nil {
        cur := pos.Next
        if m[cur.Val] {
            pos.Next = pos.Next.Next
        } else {
            m[cur.Val] = true
            pos = pos.Next
        }
    }

    return head
}