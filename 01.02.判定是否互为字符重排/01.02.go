// 解法1：两个map
func CheckPermutation(s1 string, s2 string) bool {
    if len(s1) != len(s2) {
        return false
    }

    m1, m2 := make(map[rune]int), make(map[rune]int)
    for _, r := range []rune(s1) {
        if m1[r] > 0 {
            m1[r]++
        } else {
            m1[r] = 1
        }
    }
    for _, r := range []rune(s2) {
        if m2[r] > 0 {
            m2[r]++
        } else {
            m2[r] = 1
        }
    }

    return reflect.DeepEqual(m1, m2)
}

// 解法2：字符串排序
func CheckPermutation(s1 string, s2 string) bool {
    if len(s1) != len(s2) {
        return false
    }

    r1, r2 := []rune(s1), []rune(s2)
    sort.Slice(r1, func(i int, j int) bool { return r1[i] < r1[j] })
    sort.Slice(r2, func(i int, j int) bool { return r2[i] < r2[j] })

    return reflect.DeepEqual(r1, r2)
}