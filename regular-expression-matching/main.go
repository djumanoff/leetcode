package main

import (
	"fmt"
)

// "mississippi"
// "mis*is*ip*."
// true

// "aab"
// "c*a*b"
// true

// "ab"
// ".*c"
// false

// "aaa"
// "a*a"
// true

//"aaa"
//"ab*a*c*a"
//true
func main() {
	//fmt.Println(isMatch("aaa", "ab*a*c*a")) // true
	//fmt.Println(isMatch("ab", ".*c")) // false
	fmt.Println(isMatch("mississippi", "mis*is*ip*.")) // true
	//fmt.Println(isMatch("aab", "c*a*b"))
	//fmt.Println(isMatch("aaa", "a*a"))
	//fmt.Println(isMatch("aa", "a"))
}

func isMatch(s string, p string) bool {
	dp := make([][]int, len(s)+1)
	for i := 0; i < len(s)+1; i++ {
		dp[i] = make([]int, len(p)+1)
		dp[i][0] = 0
	}

	dp[0][0] = 1
	for i := 1; i < len(p)+1; i++ {
		if p[i-1] == '*' {
			dp[0][i] = dp[0][i-2]
		} else {
			dp[0][i] = 0
		}
	}

	for i := 1; i < len(s)+1; i++ {
		for j := 1; j < len(p)+1; j++ {
			fmt.Println(string(s[i-1]), string(p[j-1]), s[i-1] == p[j-1])
			if s[i-1] == p[j-1] || p[j-1] == '.' {
				dp[i][j] = dp[i-1][j-1]
			} else if p[j-1] == '*' {
				if p[j-2] == s[i-1] || p[j-2] == '.' {
					dp[i][j] = dp[i][j-2] | dp[i-1][j]
				} else {
					dp[i][j] = dp[i][j-2]
				}
			} else if s[i-1] != p[j-1] {
				dp[i][j] = 0
			}
		}
	}

	for i := 0; i < len(s)+1; i++ {
		for j := 0; j < len(p)+1; j++ {
			fmt.Print(dp[i][j], " ")
		}
		fmt.Println()
	}

	return dp[len(s)][len(p)] == 1
}
