use std::collections::HashSet;
impl Solution {
    pub fn is_unique(astr: String) -> bool {
        let mut hs: HashSet<char> = HashSet::new();
        for c in astr.chars() {
            if hs.contains(&c) == true {
                return false;
            }
            hs.insert(c);
        }
        return true;
    }
}
