func exchangeBits(num int) int {
	even := num & 0x55555555
	odd := num & 0xaaaaaaaa
	even = even << 1
	odd = odd >> 1
	return even + odd
}