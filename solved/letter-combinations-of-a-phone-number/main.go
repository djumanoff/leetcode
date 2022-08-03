package main

import "fmt"

func main() {
	fmt.Println(letterCombinations("5678"))
	// ["adg","adh","adi","aeg","aeh","aei","afg","afh","afi","bdg","bdh","bdi","beg","beh","bei","bfg","bfh","bfi",
	// "cdg","cdh","cdi","ceg","ceh","cei","cfg","cfh","cfi"]

	// [adg adh adi aeg aeh aei afg afh afi bdg bdh bdi beg beh bei bfg bfh bfi cdg cdh cdi ceg ceh cei cfg cfh cfi
	// dg dh di eg eh ei fg fh fi]
}

func letterCombinations(digits string) []string {
	ret := []string{}
	if digits == "" {
		return ret
	}
	letterArr := [][]string{}
	for _, ch := range digits {
		letterArr = append(letterArr, getLettersOfNum(ch))
	}

	combs := getCombinations(letterArr)
	for i := 0; i < len(combs); i++ {
		if len(combs[i]) < len(digits) {
			continue
		}
		ret = append(ret, combs[i])
	}
	return ret
}

func getCombinations(arrOfArr [][]string) []string {
	ret := []string{}
	if len(arrOfArr) == 0 {
		return ret
	}
	if len(arrOfArr) == 1 {
		return arrOfArr[0]
	}
	for i := 0; i < len(arrOfArr); i++ {
		for j := 0; j < len(arrOfArr[i]); j++ {
			cpOfArr := make([][]string, len(arrOfArr))
			copy(cpOfArr, arrOfArr)
			curr := arrOfArr[i][j]
			cpOfArr = cpOfArr[i+1:]
			fmt.Println("curr=", curr, "cpOfArr=", cpOfArr)
			tempRet := getCombinations(cpOfArr)
			for k := 0; k < len(tempRet); k++ {
				fmt.Println(curr, tempRet[k])
				ret = append(ret, curr+tempRet[k])
			}
		}
	}
	return ret
}

func getLettersOfNum(num rune) []string {
	switch num {
	case '2':
		return []string{"a","b","c"}
	case '3':
		return []string{"d","e","f"}
	case '4':
		return []string{"g","h","i"}
	case '5':
		return []string{"j","k","l"}
	case '6':
		return []string{"m","n","o"}
	case '7':
		return []string{"p","q","r","s"}
	case '8':
		return []string{"t","u","v"}
	case '9':
		return []string{"w","x","y","z"}
	}
	return []string{}
}
