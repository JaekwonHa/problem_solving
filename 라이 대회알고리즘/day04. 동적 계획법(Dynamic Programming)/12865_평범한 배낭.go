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
	N      int
	K      int
	MAX    = 100001
	M      = 10007
	cache  = make([][]int, MAX)
	weight = make([]int, 101)
	value  = make([]int, 101)
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

//func step1() (result int) {
//	for i := 1; i <= K; i++ {
//		cache[i] = max(cache[i], cache[i-1])
//		for j := 0; j < N; j++ {
//			if i-weight[j] >= 0 {
//				cache[i] = max(cache[i], cache[i-weight[j]]+value[j])
//			}
//		}
//	}
//	return cache[K]
//}
//
//func step2(isVisit []bool, k int) (result int) {
//	if k <= 0 {
//		return 0
//	}
//
//	if cache[k] != -1 {
//		return cache[k]
//	}
//
//	var answer = 0
//	for j := 0; j < N; j++ {
//		if isVisit[j] == false {
//			isVisit[j] = true
//			answer = max(answer, step2(isVisit, k-weight[j])+value[j])
//			isVisit[j] = false
//		}
//	}
//	cache[k] = answer
//	return answer
//}

func main() {

	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)

	fmt.Fscanln(reader, &N, &K)

	for i := 1; i <= N; i++ {
		fmt.Fscanln(reader, &weight[i], &value[i])
	}

	cache := make([][]int, N+1)
	for i := 0; i <= N; i++ {
		cache[i] = make([]int, K+1)
	}

	for i := 1; i <= N; i++ {
		for j := 1; j <= K; j++ {
			if j-weight[i] >= 0 {
				cache[i][j] = max(cache[i-1][j], cache[i-1][j-weight[i]]+value[i])
			} else {
				cache[i][j] = cache[i-1][j]
			}
		}
	}

	fmt.Fprintln(writer, cache[N][K])
	writer.Flush()
}
