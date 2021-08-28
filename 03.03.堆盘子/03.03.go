type StackOfPlates struct {
	cap   int
	stack [][]int
}

func Constructor(cap int) StackOfPlates {
	return StackOfPlates{
		cap:   cap,
		stack: make([][]int, 0),
	}
}

func (this *StackOfPlates) Push(val int) {
	if this.cap == 0 {
		return
	}

	if len(this.stack) == 0 {
		newPlate := []int{val}
		this.stack = append(this.stack, newPlate)
		return
	}

	if len(this.stack[len(this.stack)-1]) == this.cap {
		newPlate := []int{val}
		this.stack = append(this.stack, newPlate)
		return
	}

	this.stack[len(this.stack)-1] = append(this.stack[len(this.stack)-1], val)
}

func (this *StackOfPlates) Pop() int {
	if len(this.stack) == 0 {
		return -1
	}

	plate := this.stack[len(this.stack)-1]
	v := plate[len(plate)-1]

	plate = plate[0 : len(plate)-1]
	this.stack[len(this.stack)-1] = plate

	if len(plate) == 0 {
		this.stack = this.stack[0 : len(this.stack)-1]
	}

	return v
}

func (this *StackOfPlates) PopAt(index int) int {
	n := len(this.stack)
	if index >= n {
		return -1
	}

	plate := this.stack[index]
	v := plate[len(plate)-1]
	plate = plate[0 : len(plate)-1]
	this.stack[index] = plate

	if len(plate) == 0 {
		tmp := this.stack[index+1:]
		this.stack = this.stack[:index]
		this.stack = append(this.stack, tmp...)
	}

	return v
}

/**
 * Your StackOfPlates object will be instantiated and called as such:
 * obj := Constructor(cap);
 * obj.Push(val);
 * param_2 := obj.Pop();
 * param_3 := obj.PopAt(index);
 */