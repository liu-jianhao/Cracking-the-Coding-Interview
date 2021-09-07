/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func inorderSuccessor(root *TreeNode, p *TreeNode) *TreeNode {
	if p.Right != nil {
		p = p.Right
		for p.Left != nil {
			p = p.Left
		}
		return p
	}

	var res *TreeNode
	for root != p {
		if root.Val < p.Val {
			root = root.Right
		} else {
			res = root
			root = root.Left
		}
	}
	return res
}