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

func sum(numbers ...int) (result int) {
	for _, number := range numbers {
		result += number
	}
	return result
}

func main() {

	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)

	fmt.Fscanln(reader, &N)

	cache[0] = 1
	cache[1] = 1
	cache[2] = 1

	for i := 3; i <= N; i++ {
		cache[i] = sum(cache[0 : i-1]...)
	}

	fmt.Fprintln(writer, cache[N])
	writer.Flush()
}
