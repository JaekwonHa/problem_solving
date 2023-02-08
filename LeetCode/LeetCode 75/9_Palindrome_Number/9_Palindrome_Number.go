package main

import "fmt"

func isPalindrome(x int) bool {
	if x < 0 {
		return false
	}

	nums := []int{}

	remain := x
	for remain > 0 {
		last_digit := remain % 10
		remain = remain / 10
		nums = append(nums, last_digit)
	}

	fmt.Println(nums)

	for i, num := range nums {
		if num != nums[len(nums)-1-i] {
			return false
		}
	}
	return true
}

func main() {
	x := 123
	result := isPalindrome(x)
	fmt.Println(result)
}
