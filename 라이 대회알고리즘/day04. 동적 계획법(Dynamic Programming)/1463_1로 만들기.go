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
	MAX   = 1000001
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

	cache[1] = 0
	cache[2] = 1
	cache[3] = 1

	for i := 4; i <= N; i++ {
		var answer = MaxInt
		if i%3 == 0 {
			answer = min(answer, cache[i/3]+1)
		}
		if i%2 == 0 {
			answer = min(answer, cache[i/2]+1)
		}
		answer = min(answer, cache[i-1]+1)
		cache[i] = answer
	}

	fmt.Fprintln(writer, cache[N])
	writer.Flush()
}
