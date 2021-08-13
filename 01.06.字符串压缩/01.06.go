func compressString(S string) string {
    sBytes := []byte(S)
    res := make([]byte, 0, len(sBytes))
    i := 0
    for i < len(sBytes) {
        j := i
        for j < len(sBytes) && S[i] == S[j] {
            j++
        }
        res = append(res, sBytes[i])
        res = append(res, []byte(strconv.Itoa(j-i))...)
        i = j
    }

    if len(res) >= len(sBytes) {
        return S
    }
    return string(res)
}