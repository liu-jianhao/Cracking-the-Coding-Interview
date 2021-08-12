impl Solution {
    pub fn one_edit_away(first: String, second: String) -> bool {
        let mut first_chars: Vec<char> = first.chars().collect();
        let mut second_chars: Vec<char> = second.chars().collect();

        if first_chars.len() > second_chars.len() {
            let mut tmp: Vec<char> = first_chars;
            first_chars = second_chars;
            second_chars = tmp;
        }
        if second_chars.len() - first_chars.len() > 1 {
            return false;
        }

        let mut i = 0;
        while i < first_chars.len() {
            if first_chars[i] != second_chars[i] {
                if first_chars[i..] == second_chars[i + 1..] {
                    return true;
                }
                if first_chars[i + 1..] == second_chars[i + 1..] {
                    return true;
                }
                return false;
            }
            i += 1;
        }
        true
    }
}
