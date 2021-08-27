type TripleInOne struct {
	data     []int
	stackPtr [3]int
}

func Constructor(stackSize int) TripleInOne {
	return TripleInOne{
		data:     make([]int, 3*stackSize),
		stackPtr: [3]int{0, stackSize, stackSize * 2},
	}
}

func (this *TripleInOne) Push(stackNum int, value int) {
	if this.IsFull(stackNum) {
		return
	}
	this.data[this.stackPtr[stackNum]] = value
	this.stackPtr[stackNum]++
}

func (this *TripleInOne) Pop(stackNum int) int {
	if this.IsEmpty(stackNum) {
		return -1
	}
	value := this.data[this.stackPtr[stackNum]-1]
	this.stackPtr[stackNum]--
	return value
}

func (this *TripleInOne) Peek(stackNum int) int {
	if this.IsEmpty(stackNum) {
		return -1
	}
	return this.data[this.stackPtr[stackNum]-1]
}

func (this *TripleInOne) IsEmpty(stackNum int) bool {
	switch stackNum {
	case 0:
		return this.stackPtr[0] == 0
	case 1:
		return this.stackPtr[1] == len(this.data)/3
	case 2:
		return this.stackPtr[2] == len(this.data)/3*2
	}
	return true
}

func (this *TripleInOne) IsFull(stackNum int) bool {
	switch stackNum {
	case 0:
		return this.stackPtr[0] == len(this.data)/3
	case 1:
		return this.stackPtr[1] == (len(this.data)/3)*2
	case 2:
		return this.stackPtr[2] == len(this.data)
	}
	return true
}

/**
 * Your TripleInOne object will be instantiated and called as such:
 * obj := Constructor(stackSize);
 * obj.Push(stackNum,value);
 * param_2 := obj.Pop(stackNum);
 * param_3 := obj.Peek(stackNum);
 * param_4 := obj.IsEmpty(stackNum);
 */