/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func listOfDepth(tree *TreeNode) []*ListNode {
	res := make([]*ListNode, 0)
	if tree == nil {
		return res
	}

	que := make([]*TreeNode, 0)
	que = append(que, tree)

	for len(que) > 0 {
		var head, prev *ListNode
		size := len(que)

		for i := 0; i < size; i++ {
			cur := que[0]
			que = que[1:]

			node := &ListNode{Val: cur.Val}

			if head == nil {
				head = node
			} else {
				prev.Next = node
			}
			prev = node

			if cur.Left != nil {
				que = append(que, cur.Left)
			}
			if cur.Right != nil {
				que = append(que, cur.Right)
			}
		}

		res = append(res, head)
	}

	return res
}