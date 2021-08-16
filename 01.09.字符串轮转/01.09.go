func isFlipedString(s1 string, s2 string) bool {
    if len(s1) != len(s2) {
        return false
    }

    s1 += s1
    if strings.Contains(s1, s2) {
        return true
    }

    return false
}