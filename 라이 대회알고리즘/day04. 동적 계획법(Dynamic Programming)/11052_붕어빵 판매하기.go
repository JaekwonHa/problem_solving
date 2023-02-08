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
	MAX   = 1001
	cache = make([]int, MAX)
	cards = make([]int, MAX)
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
		fmt.Fscanf(reader, "%d ", &cards[i])
		cache[i] = cards[i]
	}
	for i := 1; i <= N; i++ {
		for j, card := range cards {
			if i-j >= 0 {
				cache[i] = max(cache[i], cache[i-j]+card)
			}
		}
	}

	fmt.Fprintln(writer, cache[N])
	writer.Flush()
}
