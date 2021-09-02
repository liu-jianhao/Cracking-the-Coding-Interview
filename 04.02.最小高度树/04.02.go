/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func sortedArrayToBST(nums []int) *TreeNode {
    if len(nums) == 0 {
        return nil
    }
    if len(nums) == 1 {
        return &TreeNode{Val: nums[0]}
    }

    mid := len(nums) / 2
    head := &TreeNode{
        Val: nums[mid],
    }
    head.Left = sortedArrayToBST(nums[:mid])
    head.Right = sortedArrayToBST(nums[mid+1:])
    return head
}