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

var (
	N       int
	MAX     = 1001
	cache   = make([]int, MAX)
	numbers = make([]int, MAX)
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

func main() {

	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)

	fmt.Fscanln(reader, &N)

	for i := 1; i <= N; i++ {
		fmt.Fscanf(reader, "%d ", &numbers[i])
		cache[i] = numbers[i]
	}

	for i := 2; i <= N; i++ {
		var j int
		for j = i - 1; j > 0; j-- {
			if numbers[j] < numbers[i] {
				cache[i] = max(cache[i], cache[j]+numbers[i])
			}
		}
	}

	fmt.Fprintln(writer, max(cache...))
	writer.Flush()
}
