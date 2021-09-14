func printBin(num float64) string {
	res := "0."
	for num > 0 {
		num = num * 2
		if num >= 1 {
			res = res + "1"
			num = num - 1
		} else {
			res = res + "0"
		}

		if len(res) > 32 {
			return "ERROR"
		}
	}
	return res
}