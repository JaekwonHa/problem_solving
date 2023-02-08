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
	N              int
	MAX            = 100001
	numbers        = make([]int, MAX)
	sumSegmentTree = make([]int, MAX*2+1)
	minSegmentTree = make([]int, MAX*2+1)
	pNumbers       = make([]int, MAX+1)
)

func sum(numbers ...int) (result int) {
	for _, number := range numbers {
		result += number
	}
	return result
}

func min(numbers ...int) (result int) {
	result = MaxInt
	for _, number := range numbers {
		if number < result {
			result = number
		}
	}
	return result
}

func max(numbers ...int) (result int) {
	result = MinInt
	for _, number := range numbers {
		if result < number {
			result = number
		}
	}
	return result
}

func step1(i int, j int, numbers []int) (result int) {
	if i == j {
		return numbers[i] * numbers[i]
	}
	var localMaximum = sum(numbers[i:j]...) * min(numbers[i:j]...)
	return max(localMaximum, step1(i+1, j, numbers), step1(i, j-1, numbers))
}

func step4(i int, j int) (result int) {
	if i == j {
		return numbers[i] * numbers[i]
	}
	var localMaximum = (pNumbers[j] - pNumbers[i-1]) * min(numbers[i:j+1]...)
	return max(localMaximum, step4(i+1, j), step4(i, j-1))
}

func step2(i int, j int) (result int) {
	step2_init_sum_segmentTree(1, i, j)
	step2_init_min_segmentTree(1, i, j)

	return step2_recursive(i, j)
}

func step2_recursive(l int, r int) (result int) {
	if l == r {
		return numbers[l] * numbers[l]
	}

	var localMaximum = step2_query_sum_segmentTree(1, 1, N, l, r) * step2_query_min_segmentTree(1, 1, N, l, r)
	return max(localMaximum, step2_recursive(l+1, r), step2_recursive(l, r-1))
}

func step2_init_sum_segmentTree(node int, l int, r int) (result int) {
	if l == r {
		sumSegmentTree[node] = numbers[l]
		return sumSegmentTree[node]
	}
	var mid = (l + r) / 2
	sumSegmentTree[node] = sum(step2_init_sum_segmentTree(node*2, l, mid), step2_init_sum_segmentTree(node*2+1, mid+1, r))
	return sumSegmentTree[node]
}

func step2_query_sum_segmentTree(node int, s int, e int, l int, r int) (result int) {
	if e < l || r < s {
		return 0
	}
	if l <= s && e <= r {
		return sumSegmentTree[node]
	}
	var mid = (s + e) / 2
	return sum(step2_query_sum_segmentTree(node*2, s, mid, l, r), step2_query_sum_segmentTree(node*2+1, mid+1, e, l, r))
}

func step2_init_min_segmentTree(node int, l int, r int) (result int) {
	if l == r {
		minSegmentTree[node] = numbers[l]
		return minSegmentTree[node]
	}
	var mid = (l + r) / 2
	minSegmentTree[node] = min(step2_init_min_segmentTree(node*2, l, mid), step2_init_min_segmentTree(node*2+1, mid+1, r))
	return minSegmentTree[node]
}

func step2_query_min_segmentTree(node int, s int, e int, l int, r int) (result int) {
	if e < l || r < s {
		return MaxInt
	}
	if l <= s && e <= r {
		return minSegmentTree[node]
	}
	var mid = (s + e) / 2
	return min(step2_query_min_segmentTree(node*2, s, mid, l, r), step2_query_min_segmentTree(node*2+1, mid+1, e, l, r))
}

func step3(s int, e int) (result int) {
	if s == e {
		return numbers[s] * numbers[e]
	}

	var mid = (s + e) / 2
	result = max(step3(s, mid), step3(mid+1, e))

	var localSum, localMin, l, r = numbers[mid], numbers[mid], mid, mid
	for s < l || r < e {
		var p = -1
		if s < l {
			p = numbers[l-1]
		}
		var q = -1
		if r < e {
			q = numbers[r+1]
		}
		if p < q {
			localSum = localSum + q
			if q < localMin && q != -1 {
				localMin = q
			}
			r += 1
		} else {
			localSum = localSum + p
			if p < localMin && p != -1 {
				localMin = p
			}
			l -= 1
		}
		result = max(result, localSum*localMin)
	}
	return result
}

func main() {

	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)

	fmt.Fscanln(reader, &N)

	for i := 1; i <= N; i++ {
		fmt.Fscanf(reader, "%d ", &numbers[i])
	}

	sumSegmentTree = make([]int, N*4)
	minSegmentTree = make([]int, N*4)

	//var answer = step1(0, N, numbers)
	//var answer = step2(1, N)
	//var answer = step3(1, N)

	for i := 1; i <= N; i++ {
		pNumbers[i] = pNumbers[i-1] + numbers[i]
	}
	var answer = step4(1, N)

	fmt.Fprintln(writer, answer)
	writer.Flush()
}
