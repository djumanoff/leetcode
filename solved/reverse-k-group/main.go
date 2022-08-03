package main

import "fmt"

func main() {
	l := &ListNode{1, &ListNode{2, &ListNode{3, &ListNode{4, &ListNode{5, nil}}}}}
	print_r(reverseKGroup(l, 2))

	l = &ListNode{1, &ListNode{2, &ListNode{3, &ListNode{4, &ListNode{5, nil}}}}}
	print_r(reverseKGroup(l, 3))
}


// Definition for singly-linked list.
type ListNode struct {
	Val int
	Next *ListNode
}

func reverseKGroup(head *ListNode, k int) *ListNode {
	cnt := 0
	start := head
	var cont, ret *ListNode
	for head != nil {
		cnt++
		if cnt == k {
			tmp := head.Next
			t := reverseList(start, head.Next, cont)
			if ret == nil {
				ret = t
			}
			cont = start
			start = tmp
			cnt = 0
			head = tmp
		} else {
			head = head.Next
		}
	}
	return ret
}

// 1 -> 2 -> 3 -> 4 -> 5
func reverseList(curr, end, cont *ListNode) *ListNode {
	if curr == nil {
		return nil
	}
	if curr.Next == nil {
		return curr
	}
	var prev = end
	for curr != nil && curr != end {
		next := curr.Next
		curr.Next = prev
		prev = curr
		curr = next
	}
	if cont != nil {
		cont.Next = prev
	}
	return prev
}

func print_r(l *ListNode) {
	for l != nil {
		fmt.Print(l.Val, " : ")
		l = l.Next
	}
	fmt.Println()
}