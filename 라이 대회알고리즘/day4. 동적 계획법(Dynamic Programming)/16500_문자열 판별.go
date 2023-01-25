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
	S     string
	N     int
	MAX   = 101
	cache = make([]int, MAX)
	words = make([]string, 101)
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

	fmt.Fscanln(reader, &S)
	fmt.Fscanln(reader, &N)

	for i := 0; i < N; i++ {
		fmt.Fscanln(reader, &words[i])
	}

	for i := 1; i <= len(S); i++ {
		for j := 0; j < N; j++ {
			if i-len(words[j]) >= 0 {
				var check = true
				for k := 0; k < len(words[j]); k++ {
					if words[j][k] != S[i-(len(words[j])-k)] {
						check = false
						break
					}
				}
				if check == true {
					if i == len(words[j]) {
						cache[i] = 1
					} else {
						cache[i] = max(cache[i], cache[i-len(words[j])])
					}
				}
			}
		}
	}

	fmt.Fprintln(writer, cache[len(S)])
	writer.Flush()
}
