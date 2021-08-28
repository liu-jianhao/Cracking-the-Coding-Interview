type MinStack struct {
	data     []int
	minStack []int
}

/** initialize your data structure here. */
func Constructor() MinStack {
	return MinStack{
		data:     make([]int, 0),
		minStack: make([]int, 0),
	}
}

func (this *MinStack) Push(x int) {
	this.data = append(this.data, x)
	if len(this.minStack) == 0 {
		this.minStack = append(this.minStack, x)
	} else {
		if this.minStack[len(this.minStack)-1] < x {
			this.minStack = append(this.minStack, this.minStack[len(this.minStack)-1])
		} else {
			this.minStack = append(this.minStack, x)
		}
	}
}

func (this *MinStack) Pop() {
	if len(this.data) == 0 {
		return
	}
	this.data = this.data[0 : len(this.data)-1]
	this.minStack = this.minStack[0 : len(this.minStack)-1]
}

func (this *MinStack) Top() int {
	if len(this.data) == 0 {
		return -1
	}
	return this.data[len(this.data)-1]
}

func (this *MinStack) GetMin() int {
	if len(this.minStack) == 0 {
		return -1
	}
	return this.minStack[len(this.minStack)-1]
}

/**
 * Your MinStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * obj.Pop();
 * param_3 := obj.Top();
 * param_4 := obj.GetMin();
 */