package main

import "fmt"

type ns struct{}

func add(s map[byte]ns, v byte) map[byte]ns {
	s[v] = ns{}
	return s
}
func isIsomorphic(s string, t string) bool {
	set_s := make(map[byte]ns)
	set_t := make(map[byte]ns)
	for i := range s {
		set_s = add(set_s, s[i])
		set_t = add(set_t, t[i])
	}
	if len(set_s) != len(set_t) {
		return false
	}
	hash := make(map[byte]byte)
	for i := range s {
		val, ok := hash[s[i]]
		if ok && val != t[i] {
			return false
		}
		hash[s[i]] = t[i]
	}
	return true
}

func main() {

	fmt.Println(isIsomorphic("foo", "bar"))
	fmt.Println(isIsomorphic("bacd", "baba"))
	fmt.Println(isIsomorphic("paper", "title"))
}
