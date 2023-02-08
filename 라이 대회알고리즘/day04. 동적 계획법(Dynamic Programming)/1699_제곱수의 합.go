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
	N     int
	MAX   = 100001
	cache = make([]int, MAX)
)

func min(numbers ...int) (result int) {
	result = MaxInt
	for _, number := range numbers {
		if number < result {
			result = number
		}
	}
	return result
}

func main() {

	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)

	fmt.Fscanln(reader, &N)

	cache[1] = 1

	for i := 2; i <= N; i++ {
		var answer = MaxInt
		for j := 1; j*j <= i; j++ {
			if i == j*j {
				answer = 1
			} else {
				answer = min(answer, cache[i-(j*j)]+1)
			}
		}
		cache[i] = answer
	}

	fmt.Fprintln(writer, cache[N])
	writer.Flush()
}
