package main

import "fmt"

func longestCommonPrefix(strs []string) string {
	var result string

	for i, v := range strs[0] {
		for _, str := range strs {
			if len(str) <= i || str[i] != byte(v) {
				return result
			}
		}
		result += string(v)
	}
	return result
}

func main() {

	input := []string{"flower", "flow", "flight"}
	fmt.Print(longestCommonPrefix(input))
}
