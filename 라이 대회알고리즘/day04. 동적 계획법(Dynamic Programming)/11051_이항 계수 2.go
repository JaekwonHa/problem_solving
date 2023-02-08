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
	MAX   = 1001
	M     = 10007
	cache = make([][]int, MAX)
)

func main() {

	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)

	fmt.Fscanln(reader, &N, &K)

	for i := 1; i < MAX; i++ {
		cache[i] = make([]int, i+1)
	}

	cache[1][0] = 1
	cache[1][1] = 1

	for i := 2; i <= N; i++ {
		cache[i][0] = 1
		cache[i][i] = 1
		for j := 1; j < i; j++ {
			cache[i][j] = (cache[i-1][j-1] + cache[i-1][j]) % M
		}
	}
	fmt.Fprintln(writer, cache[N][K])
	writer.Flush()
}
