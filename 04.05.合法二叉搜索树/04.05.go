/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isValidBST(root *TreeNode) bool {
	return helper(root, math.MinInt64, math.MaxInt64)
}

func helper(root *TreeNode, lower, upper int64) bool {
	if root == nil {
		return true
	}

	if int64(root.Val) <= lower || int64(root.Val) >= upper {
		return false
	}

	return helper(root.Left, lower, int64(root.Val)) && helper(root.Right, int64(root.Val), upper)
}

// 中序遍历
func isValidBST(root *TreeNode) bool {
	st := make([]*TreeNode, 0)
	inorder := math.MinInt64

	for len(st) > 0 || root != nil {
		for root != nil {
			st = append(st, root)
			root = root.Left
		}

		root = st[len(st)-1]
		st = st[:len(st)-1]

		if root.Val <= inorder {
			return false
		}

		inorder = root.Val
		root = root.Right
	}

	return true
}