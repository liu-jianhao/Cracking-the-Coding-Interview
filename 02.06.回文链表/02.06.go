/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

 // 转成数组
 func isPalindrome(head *ListNode) bool {
    vals := make([]int, 0)
    for ; head != nil; head = head.Next {
        vals = append(vals, head.Val)
    }

    n := len(vals)
    for i, v := range vals[:n/2] {
        if v != vals[n-1-i] {
            return false
        }
    }
    return true
}


// 递归
 func isPalindrome(head *ListNode) bool {
    front := head
    var recursivelyCheck func(*ListNode) bool
    recursivelyCheck = func(curNode *ListNode) bool {
        if curNode != nil {
            if !recursivelyCheck(curNode.Next) {
                return false
            }
            if curNode.Val != front.Val {
                return false
            }
            front = front.Next
        }
        return true
    }
    return recursivelyCheck(head)
}

// 快慢指针，反转链表比较
 func isPalindrome(head *ListNode) bool {
    if head == nil {
        return true
    }

    firstHalfEnd := endOfFirstHalf(head)
    secondHalfStart := reverseList(firstHalfEnd.Next)

    p1 := head
    p2 := secondHalfStart
    result := true
    for result && p2 != nil {
        if p1.Val != p2.Val {
            result = false
        }
        p1 = p1.Next
        p2 = p2.Next
    }

    firstHalfEnd.Next = reverseList(secondHalfStart)
    return result
}

func endOfFirstHalf(head *ListNode) *ListNode {
    fast, slow := head, head
    for fast.Next != nil && fast.Next.Next != nil {
        fast = fast.Next.Next
        slow = slow.Next
    }
    return slow
}

func reverseList(head *ListNode) *ListNode {
    var prev, cur *ListNode = nil, head
    for cur != nil {
        next := cur.Next
        cur.Next = prev
        prev = cur
        cur = next
    }
    return prev
}