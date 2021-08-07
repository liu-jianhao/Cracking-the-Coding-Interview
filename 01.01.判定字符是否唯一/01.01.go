func isUnique(astr string) bool {
    m := make(map[rune]bool)
    for _, r := range []rune(astr) {
        if m[r] == true {
            return false
        }
        m[r] = true
    }
    return true
}