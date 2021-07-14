package main

import (
	"fmt"
	. "github.com/djumanoff/acm"
	"sort"
)

func main() {
	reader := StdinReader()

	words := ReadStringSlice(reader)
	k := ReadInt(reader)

	fmt.Println(topKFrequent(words, k))
}

func topKFrequent(words []string, k int) []string {
	var freqWords []string

	cntMap := map[string]int{}
	for i := 0; i < len(words); i++ {
		cntMap[words[i]]++
	}

	cntMapOfStr := map[int][]string{}
	for word, count := range cntMap {
		if cntMapOfStr[count] == nil {
			cntMapOfStr[count] = []string{}
		}
		cntMapOfStr[count] = append(cntMapOfStr[count], word)
	}

	var cntarr []int
	for count, _ := range cntMapOfStr {
		cntarr = append(cntarr, count)
		sort.Strings(cntMapOfStr[count])
	}
	sort.Ints(cntarr)

	for i := len(cntarr)-1; i >= 0; i-- {
		freqWords = append(freqWords, cntMapOfStr[cntarr[i]]...)
	}

	return freqWords[:k]
}
