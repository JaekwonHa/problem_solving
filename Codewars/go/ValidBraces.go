package main

import "fmt"

func ValidBraces(str string) bool {

	braces := map[string]string {
		"{": "}",
		"[": "]",
		"(": ")",
	}

	stack := newStack()

	for _, ch := range str {
		_, exists := braces[string(ch)]
		if exists {
			stack.push(string(ch))
		} else if stack.len() == 0 || string(ch) != braces[stack.pop()] {
			return false
		}
	}
	return stack.len() == 0
}

type Stack struct {
	s []string
	size int
}

func newStack() *Stack {
	return &Stack{}
}

func (stack *Stack) push(v string) {
	stack.s = append(stack.s, v)
	stack.size++
}

func (stack *Stack) pop() string  {
	if stack.size == 0 {
		return ""
	}
	itemS, itemsS := stack.s[stack.size-1], stack.s[:stack.size-1]
	stack.s = itemsS
	stack.size--
	return itemS
}

func (stack *Stack) len() int  {
	return stack.size
}

func main() {
	fmt.Println(ValidBraces("(){}[]"))
	fmt.Println(ValidBraces("[({})](]"))
}
