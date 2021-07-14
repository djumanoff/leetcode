package main

import "fmt"

func main() {
	fmt.Println(longestValidParentheses(")()())"))
	fmt.Println(longestValidParentheses("(()"))
	fmt.Println(longestValidParentheses("())"))
}

type Stack struct {
	data []*Item
}

func (st *Stack) Empty() bool {
	return len(st.data) == 0
}

func (st *Stack) Push(item *Item) {
	st.data = append(st.data, item)
}

func (st *Stack) Pop() *Item {
	item := st.data[len(st.data)-1]
	st.data = st.data[:len(st.data)-1]
	return item
}

func (st *Stack) Peek() *Item {
	if len(st.data) == 0 {
		return nil
	}
	return st.data[len(st.data)-1]
}

type Item struct {
	Char rune
	Pos  int
}

func longestValidParentheses(s string) int {
	st := &Stack{
		data: []*Item{},
	}
	for i, ch := range s {
		curr := &Item{ch, i}
		switch ch {
		case '(':
			st.Push(curr)
		case ')':
			item := st.Peek()
			if item != nil && item.Char == '(' {
				st.Pop()
			} else {
				st.Push(curr)
			}
		}
	}
	if st.Empty() {
		return len(s)
	}
	curr := st.Pop()
	max := len(s) - 1 - curr.Pos
	for !st.Empty() {
		item := st.Pop()
		dist := curr.Pos - item.Pos - 1
		if dist > max {
			max = dist
		}
		curr = item
	}
	if curr.Pos > max {
		max = curr.Pos
	}
	return max
}
