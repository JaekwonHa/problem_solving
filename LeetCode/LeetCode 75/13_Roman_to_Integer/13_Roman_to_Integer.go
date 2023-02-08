package main

import "fmt"

func romanToInt(s string) int {
	symbolMap := map[rune]int{
		'I': 1,
		'V': 5,
		'X': 10,
		'L': 50,
		'C': 100,
		'D': 500,
		'M': 1000,
	}
	prev := rune(0)
	result := 0
	for _, c := range s {
		result += symbolMap[c]
		if (c == 'V' || c == 'X') && prev == 'I' {
			result -= 2 * symbolMap[prev]
		} else if (c == 'L' || c == 'C') && prev == 'X' {
			result -= 2 * symbolMap[prev]
		} else if (c == 'D' || c == 'M') && prev == 'C' {
			result -= 2 * symbolMap[prev]
		}
		prev = c
	}
	return result
}

func main() {
	s := "MCMXCIV"
	fmt.Println(romanToInt(s))
}
