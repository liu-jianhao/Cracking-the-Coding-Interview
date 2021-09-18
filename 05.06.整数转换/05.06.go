func convertInteger(A int, B int) int {
	n := int32(A ^ B)
	cnt := 0
	for n != 0 {
		n = n & (n - 1)
		cnt++
	}
	return cnt
}