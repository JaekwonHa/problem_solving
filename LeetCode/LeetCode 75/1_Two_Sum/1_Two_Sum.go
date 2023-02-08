package main

import "fmt"

func twoSum(nums []int, target int) []int {
	cache := make(map[int]int)
	for i, one := range nums {
		cache[one] = i
	}
	for i, one := range nums {
		two := target - one
		j, ok := cache[two]
		if ok == true && i != j {
			return []int{i, j}
		}
	}
	return []int{0, 1}
}

func main() {
	nums := []int{2, 7, 11, 15}
	target := 9

	result := twoSum(nums, target)
	fmt.Print(result)
}
