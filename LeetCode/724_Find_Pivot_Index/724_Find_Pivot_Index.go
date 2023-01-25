package main

import "fmt"

func pivotIndex(nums []int) int {
	partial_sum := []int{0}
	for i := 0; i < len(nums); i++ {
		partial_sum = append(partial_sum, nums[i]+partial_sum[i])
	}
	partial_sum = append(partial_sum, 0)

	for i := 0; i < len(nums); i++ {
		if partial_sum[i] == partial_sum[len(nums)]-partial_sum[i+1] {
			return i
		}
	}
	return -1
}

func main() {
	nums := []int{1, 7, 3, 6, 5, 6}
	fmt.Print(pivotIndex(nums))
}
