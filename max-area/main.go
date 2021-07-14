package main

import "fmt"

func main() {
	fmt.Println(maxArea([]int{
		4,3,2,1,4,
	}))
}

func maxArea(height []int) int {
	max := 0
	for i := 0; i < len(height)-1; i++ {
		for j := i+1; j < len(height); j++ {
			s := min(height[i], height[j]) * (j-i)
			if s > max {
				max = s
			}
		}
	}
	return max
}

func min(a, b int) int {
	if a > b {
		return b
	} else {
		return a
	}
}
