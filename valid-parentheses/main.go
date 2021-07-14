package main

import "fmt"

func main() {
	fmt.Println(isValid("()[]{}"))
	fmt.Println(isValid("([)]"))
}

func isValid(s string) bool {
	st := &stack{}
	for _, ch := range s {
		switch ch {
		case '(':
			st.Push(1)
		case ')':
			if st.Empty() {
				return false
			}
			el := st.Pop()
			if el != 1 {
				return false
			}
		case '{':
			st.Push(2)
		case '}':
			if st.Empty() {
				return false
			}
			el := st.Pop()
			if el != 2 {
				return false
			}
		case '[':
			st.Push(3)
		case ']':
			if st.Empty() {
				return false
			}
			el := st.Pop()
			if el != 3 {
				return false
			}
		}
	}

	return st.Empty()
}

type stack []int

type Stack interface {
	Push(el int)

	Pop() int

	Peek() int

	Empty() bool
}

func (ar *stack) Push(el int) {
	*ar = append([]int{el}, *ar...)
}

func (ar *stack) Pop() int {
	el := (*ar)[0]
	*ar = (*ar)[1:]
	return el
}

func (ar stack) Peek() int {
	return ar[0]
}

func (ar stack) Empty() bool {
	return len(ar) == 0
}
