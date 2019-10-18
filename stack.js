class node {
	constructor(value) {
		this.value = value
		this.next = null
	}
}

class stack {
	constructor() {
		this.top = null
		this.bottom = null
		this.length = 0
	}
	peek() {
		return this.top
	}
	push(value) {
		const newNode = new node(value)
		if(this.length === 0) {
			this.top = newNode
			this.bottom = newNode
		} else {
			const holdPointer = this.top
			this.top = newNode
			this.top.next = holdPointer
		}
		this.length++
	}
	pop() {
		if(this.length === 0) {
			console.log('Stack underflow')
		} else {
			if (this.top === this.bottom) {
				this.bottom = null
			}
			const holdPointer = this.top
			this.top = holdPointer.next
			this.length--
			console.log(holdPointer.value +' is poped from the stack')
		}
	}
	isEmpty() {
		if(this.length === 0)
		return 'Yes, The stack is empty'
	}
}
const myStack = new stack()
console.log(myStack.isEmpty())
myStack.peek()
myStack.pop()
myStack.push(2)
myStack.push(14)
myStack.push(3)
myStack.push(5)
myStack.pop()
// myStack.pop()
// myStack.pop()
// myStack.pop()
console.log(myStack.peek())
console.log('Length of the stack is: '+ myStack.length)
