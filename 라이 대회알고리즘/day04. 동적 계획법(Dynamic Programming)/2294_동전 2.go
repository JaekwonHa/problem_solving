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
	K     int
	MAX   = 100001
	coins = make([]int, MAX)
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

	fmt.Fscanln(reader, &N, &K)

	for i := 0; i < N; i++ {
		fmt.Fscanln(reader, &coins[i])
		cache[coins[i]] = 1
	}

	for i := 1; i <= K; i++ {
		for j := 0; j < N; j++ {
			if (i-coins[j]) > 0 && cache[i-coins[j]] != 0 {
				if cache[i] == 0 {
					cache[i] = cache[i-coins[j]] + 1
				} else {
					cache[i] = min(cache[i], cache[i-coins[j]]+1)
				}
			}
		}
	}

	if cache[K] == 0 {
		fmt.Fprintln(writer, "-1")
	} else {
		fmt.Fprintln(writer, cache[K])
	}
	writer.Flush()
}
