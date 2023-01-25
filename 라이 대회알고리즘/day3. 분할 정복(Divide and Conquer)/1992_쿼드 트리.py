import sys
readline = sys.stdin.readline


def step1(x, y, length, input):
    if length == 0:
        return ""
    
    prev = input[x][y]
    for i in range(x, x+length):
        for j in range(y, y+length):
            if input[i][j] != prev:
                next_length = length//2
                return f"({step1(x, y, next_length, input)}{step1(x, y+next_length, next_length, input)}{step1(x+next_length, y, next_length, input)}{step1(x+next_length, y+next_length, next_length, input)})"
    return f"{prev}"

if __name__ == '__main__':
    N = int(readline())

    input = [readline() for _ in range(N)]

    print(step1(0, 0, N, input))
