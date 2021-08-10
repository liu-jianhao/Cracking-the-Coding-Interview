use std::collections::HashMap;
impl Solution {
    pub fn can_permute_palindrome(s: String) -> bool {
        let mut hm: HashMap<char, u16> = HashMap::new();
        let mut count: usize = 0;
        for c in s.chars() {
            if hm.contains_key(&c) == true {
                hm.insert(c, hm[&c] + 1);
            } else {
                hm.insert(c, 1);
            }
            if hm[&c] % 2 == 1 {
                count += 1;
            } else {
                count -= 1;
            }
        }
        count <= 1
    }
}
