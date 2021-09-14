func insertBits(N int, M int, i int, j int) int {
	for k := i; k <= j; k++ {
		if (N & (1 << k)) > 0 {
			N = N ^ (1 << k)
		}
	}

	M = M << i
	return N + M
}