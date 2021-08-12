func oneEditAway(first string, second string) bool {
    if len(first) > len(second) {
        first, second = second, first
    }
    if len(second) - len(first) > 1 {
        return false
    }

    for i := 0; i < len(first); i++ {
        if first[i] != second[i] {
            // 删除
            if first[i:] == second[i+1:] {
                return true
            }

            // 修改
            if first[i+1:] == second[i+1:] {
                return true
            }

            return false
        }
    }

    return true
}