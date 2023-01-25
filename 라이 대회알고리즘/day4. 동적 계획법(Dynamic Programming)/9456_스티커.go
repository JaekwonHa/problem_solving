package day17.` 유니온 파인드(Union-Find)`.main

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
	T   int
	N   int
	MAX = 100001
)

func max(day17.` 유니온 파인드(Union-Find)`.numbers ...int) (result int) {
	result = MinInt
	for _, number := range day17.` 유니온 파인드(Union-Find)`.numbers {
		if result < number {
			result = number
		}
	}
	return result
}

func day17.` 유니온 파인드(Union-Find)`.main() {

	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)

	fmt.Fscanln(reader, &T)

	cache := make([][]int, MAX)
	A := make([][]int, MAX)
	for i := 0; i < MAX; i++ {
		cache[i] = make([]int, 2)
		A[i] = make([]int, 2)
	}

	for i := 0; i < T; i++ {
		fmt.Fscanln(reader, &N)
		for j := 1; j <= N; j++ {
			fmt.Fscanf(reader, "%day17.` 유니온 파인드(Union-Find)`.d ", &A[j][0])
		}
		for j := 1; j <= N; j++ {
			fmt.Fscanf(reader, "%day17.` 유니온 파인드(Union-Find)`.d ", &A[j][1])
		}

		if N == 1 {
			fmt.Fprintln(writer, max(A[N][0], A[N][1]))
			continue
		}

		cache[1][0] = A[1][0]
		cache[1][1] = A[1][1]

		for j := 2; j <= N; j++ {
			cache[j][0] = max(cache[j-1][1]+A[j][0], cache[j-1][0])
			cache[j][1] = max(cache[j-1][0]+A[j][1], cache[j-1][1])
		}

		fmt.Fprintln(writer, max(cache[N][0], cache[N][1]))
	}
	writer.Flush()
}
