package main

import (
	"bufio"
	"fmt"
	"os"
)

const (
	UintSize = 32 << (^uint(0) >> 32 & 1)
	MaxInt   = 1<<(UintSize-1) - 1 // 1<<31 - 1 or 1<<63 - 1
	MinInt   = -MaxInt - 1
)

func max(numbers ...int) (result int) {
	result = MinInt
	for _, number := range numbers {
		if result < number {
			result = number
		}
	}
	return result
}

func step1(N int, M int, tree []int) (result int) {

	lb, rb := 0, max(tree...)

	for lb <= rb {
		mid := (lb + rb) / 2

		var answer = 0
		for i := range tree {
			answer += max(tree[i]-mid, 0)
		}

		if answer >= M {
			lb = mid + 1
		} else {
			rb = mid - 1
		}
	}
	return rb
}

func main() {

	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)

	var N, M int
	fmt.Fscanln(reader, &N, &M)

	tree := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Fscanf(reader, "%d ", &tree[i])
	}

	fmt.Fprintln(writer, step1(N, M, tree))
	writer.Flush()
}
