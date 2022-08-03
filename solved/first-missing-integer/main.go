package main

import (
	"fmt"
)

func main() {
	fmt.Println(firstMissingPositive([]int{3, 4, -1, 1}))
	fmt.Println(firstMissingPositive([]int{1,2,0}))
	fmt.Println(firstMissingPositive([]int{7,8,9,11,12}))
	fmt.Println(firstMissingPositive([]int{2,1}))
}

func abs(num int) int {
	if num < 0 {
		return -num
	}
	return num
}

func firstMissingPositive(nums []int) int {
	firstMissing := true
	for i := 0; i < len(nums); i++ {
		if nums[i] == 1 {
			firstMissing = false
			break
		}
	}
	if firstMissing {
		return 1
	}
	n := len(nums)
	for i := 0; i < len(nums); i++ {
		if nums[i] <= 0 || nums[i] > n {
			nums[i] = 1
		}
	}
	if n == 1 {
		return 2
	}
	for i := 0; i < len(nums); i++ {
		j := abs(nums[i])-1
		if j >-1 && nums[j] > 0 {
			nums[j] = -nums[j]
		}
	}
	for i := 0; i < len(nums); i++ {
		if nums[i] > 0 {
			return i+1
		}
	}
	return len(nums)+1
}
