func replaceSpaces(S string, length int) string {
	S = S[:length]
	bytes := []byte{}
	for i := 0; i < len(S); i++ {
		if S[i] == ' '{
			bytes = append(bytes, []byte{'%', '2', '0'}...)
		}else {
			bytes = append(bytes, S[i])
		}
	}
	return string(bytes)
}