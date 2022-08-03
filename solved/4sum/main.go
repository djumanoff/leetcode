package main

import (
	"fmt"
	"strconv"
)

func main() {
	fmt.Println(fourSum([]int{-2,-1,-1,1,1,2,2}, 0))
	//fmt.Println(fourSum([]int{-2,-1,-1,1,1,2,2}, 0))
}

func fourSum(nums []int, target int) [][]int {
	ret := [][]int{}
	if len(nums) < 4 {
		return ret
	}
	qsort(nums)
	met := map[string]bool{}

	for i := 0; i < len(nums)-3; i++ {
		fmt.Println(nums[i], target)
		if nums[i] > target {
			return ret
		}
		for j := i+1; j < len(nums)-2; j++ {
			s1 := nums[i] + nums[j]
			fmt.Println(s1, target)
			if s1 > target {
				return ret
			}
			for k := j+1; k < len(nums)-1; k++ {
				s2 := s1 + nums[k]
				fmt.Println(s2, target)
				if s2 > target {
					return ret
				}
				for l := k+1; l < len(nums); l++ {
					sum := s2 + nums[l]
					fmt.Println(sum, target)
					metK := strconv.Itoa(nums[i]) + "|" +
						strconv.Itoa(nums[j]) + "|" +
						strconv.Itoa(nums[k]) + "|" +
						strconv.Itoa(nums[l])
					if sum == target && !met[metK] {
						ret = append(ret, []int{nums[i], nums[j], nums[k], nums[l]})
						met[metK] = true
					}
				}
			}
		}
	}

	return ret
}

func qsort(arr []int) {
	l := len(arr)
	if len(arr) < 2 {
		return
	}
	pi := l/2
	left := 0
	right := l-1
	arr[pi], arr[right] = arr[right], arr[pi]
	for i := 0; i < l-1; i++ {
		if arr[i] < arr[right] {
			arr[i], arr[left] = arr[left], arr[i]
			left++
		}
	}
	arr[left], arr[right] = arr[right], arr[left]

	qsort(arr[:left])
	qsort(arr[left+1:])
}
