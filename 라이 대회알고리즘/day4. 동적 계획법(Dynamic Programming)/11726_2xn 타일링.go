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
	cache = make([]int64, MAX)
)

func main() {

	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)

	fmt.Fscanln(reader, &N)

	cache[1] = 1
	cache[2] = 2

	for i := 3; i <= N; i++ {
		cache[i] = (cache[i-1] + cache[i-2]) % 10007
	}

	fmt.Fprintln(writer, cache[N])
	writer.Flush()
}
