package main

import "fmt"

func main() {
	fmt.Println(convert("AB", 1))
}

func convert(s string, numRows int) string {
	if numRows == 1 {
		return s
	}
	strs := make([]string, numRows)
	i := 0
	up := true
	for _, ch := range s {
		strs[i] += string(ch)
		if up {
			i++
			if i == numRows-1 {
				up = false
			}
		} else {
			i--
			if i == 0 {
				up = true
			}
		}
	}
	ret := ""
	for _, str := range strs {
		ret += str
	}
	return ret
}
