// 解法1：两个map
use std::collections::HashMap;
impl Solution {
    pub fn check_permutation(s1: String, s2: String) -> bool {
        if s1.len() != s2.len() {
            return false;
        }

        let mut hm1: HashMap<char, u16> = HashMap::new();
        let mut hm2: HashMap<char, u16> = HashMap::new();

        for c in s1.chars() {
            if hm1.contains_key(&c) == true {
                hm1.insert(c, hm1[&c] + 1);
            } else {
                hm1.insert(c, 1);
            }
        }

        for c in s2.chars() {
            if hm2.contains_key(&c) == true {
                hm2.insert(c, hm2[&c] + 1);
            } else {
                hm2.insert(c, 1);
            }
        }

        hm1 == hm2
    }
}

// 解法2：字符串排序
impl Solution {
    pub fn check_permutation(s1: String, s2: String) -> bool {
        if s1.len() != s2.len() {
            return false;
        }

        let mut b1 = s1.into_bytes();
        let mut b2 = s2.into_bytes();
        b1.sort();
        b2.sort();

        b1 == b2
    }
}
