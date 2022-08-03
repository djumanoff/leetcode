package main

import "fmt"

func main() {
	fmt.Println(findSubstring("barfoothefoobarman", []string{"bar", "foo"}))

	fmt.Println(findSubstring("wordgoodgoodgoodbestword", []string{"word","good","best","word"}))

	// "wordgoodgoodgoodbestword"
	// ["word","good","best","good"]
	fmt.Println(findSubstring("wordgoodgoodgoodbestword", []string{"word","good","best","good"}))

	//"lingmindraboofooowingdingbarrwingmonkeypoundcake"
	//["fooo","barr","wing","ding","wing"]
	fmt.Println(
		findSubstring("lingmindraboofooowingdingbarrwingmonkeypoundcake",
			[]string{"fooo","barr","wing","ding","wing"}))
}

func findSubstring(s string, words []string) []int {
	ret := []int{}
	if len(words) <= 0 {
		return ret
	}
	wmp := map[string]int{}
	for _, w := range words {
		wmp[w]++
	}
	slen := len(s)
	wlen := len(words[0])
	wordcnt := len(words)
	curr := map[string]int{}
	for i := 0; i <= slen - wlen * wordcnt; i++ {
		for j := i; j < slen; j+= wlen {
			if wmp[s[j:j+wlen]] > 0 {
				curr[s[j:j+wlen]]++
				if curr[s[j:j+wlen]] > wmp[s[j:j+wlen]] {
					curr = map[string]int{}
					break
				}
			} else {
				curr = map[string]int{}
				break
			}
			foundAll := true
			for w, cnt := range wmp {
				if curr[w] != cnt {
					foundAll = false
					break
				}
			}
			if foundAll {
				ret = append(ret, i)
				curr = map[string]int{}
				break
			}
		}
	}
	return ret
}
