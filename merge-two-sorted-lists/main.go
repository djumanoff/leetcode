package main

import (
	"fmt"
)

func main() {
	print_r(
		mergeTwoLists(
			&ListNode{1, &ListNode{2, &ListNode{3, &ListNode{4, nil}}}},
			&ListNode{1, &ListNode{2, &ListNode{3, &ListNode{4, nil}}}},
		),
	)

	print_r(
		mergeTwoLists(
			&ListNode{5, nil},
			&ListNode{1, &ListNode{2, &ListNode{4, nil}}},
		),
	)
}

type ListNode struct {
	Val int
	Next *ListNode
}

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	if l1 == nil {
		return l2
	}
	if l2 == nil {
		return l1
	}
	var ret *ListNode = &ListNode{}
	r := ret
	for l1 != nil && l2 != nil {
		if l1.Val < l2.Val {
			ret.Next = l1
			l1 = l1.Next
		} else {
			ret.Next = l2
			l2 = l2.Next
		}
		ret = ret.Next
	}
	if l1 == nil {
		ret.Next = l2
	}
	if l2 == nil {
		ret.Next = l1
	}
	return r.Next
}

func print_r(l *ListNode) {
	for l != nil {
		fmt.Print(l.Val, " : ")
		l = l.Next
	}
	fmt.Println()
}
