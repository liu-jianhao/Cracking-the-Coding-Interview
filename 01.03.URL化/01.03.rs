impl Solution {
    pub fn replace_spaces(s: String, length: i32) -> String {
        let mut res = String::new();
        let mut ss = s.clone();
        ss.truncate(length as usize);

        for c in ss.chars() {
            if c == ' ' {
                res.push_str("%20");
            } else {
                res.push(c);
            }
        }
        res
    }
}
