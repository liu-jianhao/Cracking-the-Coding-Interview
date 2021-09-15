func reverseBits(num int) int {
	b := make([]int, 32, 32)
	if num < 0 {
		num = 1<<32 + num
	}
	for num > 0 {
		if num&1 == 1 {
			b = append([]int{1}, b...)
		} else {
			b = append([]int{0}, b...)
		}
		num = num >> 1
	}

	i, j, count, res := 0, 0, 0, 0
	for j < 32 {
		if b[j] == 0 {
			count++
		}
		for i <= j && count > 1 {
			if b[i] == 0 {
				count--
			}
			i++
		}
		if j-i+1 > res {
			res = j - i + 1
		}
		j++
	}
	return res
}