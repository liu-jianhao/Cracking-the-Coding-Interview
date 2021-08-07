# 题目
leetcode: https://leetcode-cn.com/problems/is-unique-lcci/

实现一个算法，确定一个字符串 s 的所有字符是否全都不同。


示例 1：
```
输入: s = "leetcode"
输出: false 
```

示例 2：
```
输入: s = "abc"
输出: true
```

限制：
- 0 <= len(s) <= 100
- 如果你不使用额外的数据结构，会很加分。

# 解答思路
这题正常思路很简单，就是遍历字符串，然后用一个hash存储每个字符，假如遇到第一个重复字符的时候就会在hash里查到，这时候返回false，如果遍历完字符串没有发现这种情况，就发挥true。

https://leetcode-cn.com/problems/is-unique-lcci/comments/

其他思路可以看看评论区，比如位运算，借用STL库判断位置等等