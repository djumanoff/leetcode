package main

import (
	"fmt"
	. "github.com/djumanoff/acm"
)

func main() {
	reader := StdinReader()

	nums := ReadIntSlice(reader)
	k := ReadInt(reader)

	fmt.Println(splitListToParts(MakeIntList(nums), k))
}

func splitListToParts(root *ListNode, k int) []*ListNode {
	listLen := LengthOfList(root)
	numOfElemList := listLen / k
	numOfLargerLists := listLen % k
	numOfElemListInLL := numOfElemList + 1
	nodes := []*ListNode{}

	for ll := 0; ll < numOfLargerLists; ll++ {
		var nodeRoot *ListNode
		if root != nil {
			nodeRoot = &ListNode{Val: root.Val}
			node := nodeRoot
			root = root.Next
			for i := 1; i < numOfElemListInLL; i++ {
				if root == nil {
					break
				}
				node.Next = &ListNode{Val: root.Val}
				node = node.Next
				root = root.Next
			}
		}
		nodes = append(nodes, nodeRoot)
	}

	for l := 0; l < k - numOfLargerLists; l++ {
		var nodeRoot *ListNode
		if root != nil {
			nodeRoot = &ListNode{Val: root.Val}
			node := nodeRoot
			root = root.Next
			for i := 1; i < numOfElemList; i++ {
				if root == nil {
					break
				}
				node.Next = &ListNode{Val: root.Val}
				node = node.Next
				root = root.Next
			}
		}
		nodes = append(nodes, nodeRoot)
	}

	return nodes
}
