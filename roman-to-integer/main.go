package main

import "fmt"

func main() {
	fmt.Println(romanToInt("LVIII"))
}

func romanToInt(s string) int {
	num := 0
	for i, ch := range s {
		var nxCh  rune
		if i < len(s)-1 {
			nxCh = rune(s[i+1])
		}
		switch ch {
		case 'I':
			if nxCh == 'V' || nxCh == 'X' {
				num -= 1
			} else {
				num += 1
			}
		case 'X':
			if nxCh == 'L' || nxCh == 'C' {
				num -= 10
			} else {
				num += 10
			}
		case 'C':
			if nxCh == 'D' || nxCh == 'M' {
				num -= 100
			} else {
				num += 100
			}
		case 'V':
			num += 5
		case 'L':
			num += 50
		case 'D':
			num += 500
		case 'M':
			num += 1000
		}
	}
	return num
}
