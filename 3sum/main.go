package main

import "fmt"

func main() {
	fmt.Println(threeSum([]int{
		0, 0, 0,
	}))
}

func threeSum(nums []int) [][]int {
	ret := [][]int{}
	qsort(nums)
	for i := 0; i < len(nums); i++ {
		if i > 0 && nums[i] == nums[i-1] {
			continue
		}
		l := i+1
		r := len(nums)-1
		for ; l < r; {
			sum := nums[i] + nums[l] + nums[r]
			if sum == 0 {
				ret = append(ret, []int{nums[i], nums[l], nums[r]})
				l++
				for ; l < r && nums[l] == nums[l-1]; l++ {}
				r--
				for ; l < r && nums[r] == nums[r+1]; r-- {}
			} else if sum > 0 {
				r--
			} else if sum < 0 {
				l++
			}
		}
	}
	return ret
}

func qsort(arr []int) {
	l := len(arr)
	if l < 2 {
		return
	}
	pi := l/2
	left := 0
	right := l-1
	arr[right], arr[pi] = arr[pi], arr[right]
	for i := 0; i < l-1; i++ {
		if arr[i] < arr[right] {
			arr[left], arr[i] = arr[i], arr[left]
			left++
		}
	}
	arr[left], arr[right] = arr[right], arr[left]
	qsort(arr[:left])
	qsort(arr[left+1:])
}
