package main

import "fmt"

func isSubsequence(s string, t string) bool {
	i := 0
	for j, _ := range t {
		if i == len(s) {
			return true
		}
		if s[i] == t[j] {
			i++
		}
	}
	if i == len(s) {
		return true
	}
	return false
}

func main() {

	fmt.Println(isSubsequence("abc", "ahbgdc"))
	fmt.Println(isSubsequence("abx", "ahbgdc"))
	fmt.Println(isSubsequence("", "ahbgdc"))
}
