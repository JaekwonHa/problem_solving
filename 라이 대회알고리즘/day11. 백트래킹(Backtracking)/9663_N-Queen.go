package main

import (
	"bufio"
	"fmt"
	"os"
)

func step1(N int, queensX []int, queensY []int, row int) (result int) {
	if row == N {
		if len(queensX) == N {
			return 1
		} else {
			return 0
		}
	}

	for col := 0; col < N; col++ {
		nx, ny := row, col
		valid := true
		for i := 0; i < len(queensX); i++ {
			queenX, queenY := queensX[i], queensY[i]
			if queenY == ny || queenX+queenY == nx+ny || queenX-queenY == nx-ny {
				valid = false
				break
			}
		}
		if valid {
			result += step1(N, append(queensX, nx), append(queensY, ny), row+1)
		}
	}
	return result
}

func main() {

	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)

	var N int
	fmt.Fscanln(reader, &N)

	fmt.Fprintln(writer, step1(N, []int{}, []int{}, 0))
	writer.Flush()
}
