func canPermutePalindrome(s string) bool {
    m := make(map[rune]int)

    count := 0
    for _, r := range s {
        m[r]++
        if m[r] % 2 == 1 {
            count++
        } else {
            count--
        }
    }

    return count <= 1
}