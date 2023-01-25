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
	M     = 10007
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

	cache := make([][]int, MAX)
	for i := 0; i < MAX; i++ {
		cache[i] = make([]int, 10)
	}

	cache[1][0] = 1
	cache[1][1] = 1
	cache[1][2] = 1
	cache[1][3] = 1
	cache[1][4] = 1
	cache[1][5] = 1
	cache[1][6] = 1
	cache[1][7] = 1
	cache[1][8] = 1
	cache[1][9] = 1

	for i := 2; i <= N; i++ {
		for j := 0; j < 10; j++ {
			cache[i][j] = (cache[i][j] + sum(cache[i-1][j:]...)%M) % M
		}
	}

	fmt.Fprintln(writer, sum(cache[N]...)%M)
	writer.Flush()
}
