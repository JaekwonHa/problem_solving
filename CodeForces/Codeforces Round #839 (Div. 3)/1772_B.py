import sys
readline=sys.stdin.readline

if __name__ == '__main__':
    N = int(readline())

    for i in range(N):
        matrix = [list(map(int, readline().split())) for _ in range(2)]
        for _ in range(4):
            matrix[0][0], matrix[0][1], matrix[1][0], matrix[1][1] = matrix[1][0], matrix[0][0], matrix[1][1], matrix[0][1]
            if matrix[0][0] < matrix[0][1] and matrix[1][0] < matrix[1][1] and matrix[0][0] < matrix[1][0] and matrix[0][1] < matrix[1][1]:
                print("YES")
                break
        else:
            print("NO")
