# 题目
https://leetcode-cn.com/problems/check-permutation-lcci/

给定两个字符串 s1 和 s2，请编写一个程序，确定其中一个字符串的字符重新排列后，能否变成另一个字符串。

示例 1：
```
输入: s1 = "abc", s2 = "bca"
输出: true 
```

示例 2：
```
输入: s1 = "abc", s2 = "bad"
输出: false
```

说明：
```
0 <= len(s1) <= 100
0 <= len(s2) <= 100
```

# 解答思路
这题解题思路也很简单，把字符串的每个字符作为key，出现的次数作为value存到map中，
然后比较两个map；

第二种解法是直接把字符串排序，比较排序后的字符串。