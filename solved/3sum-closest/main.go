package main

import "fmt"

func main() {
	fmt.Println(threeSumClosest([]int{
		-1,2,1,-4,
	}, 1))
}

func threeSumClosest(nums []int, target int) int {
	ret := 10000 * len(nums)
	qsort(nums)

	for i := 0; i < len(nums); i++ {
		if i > 0 && nums[i] == nums[i-1] {
			continue
		}
		l := i+1
		r := len(nums)-1
		for ; l < r; {
			sum := nums[i] + nums[l] + nums[r]
			if sum == target {
				return sum
			}
			d1 := dist(sum, target)
			d2 := dist(ret, target)
			if d1 < d2 {
				ret = sum
			}
			if sum > target {
				r--
				for ; l < r && nums[r] == nums[r+1]; r-- {}
			} else {
				l++
				for ; l < r && nums[l] == nums[l-1]; l++ {}
			}
		}
	}
	return ret
}

func dist(a, b int) int {
	if a > b {
		return a - b
	}
	return b - a
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
