import sys
input=sys.stdin.readline



def step1(N, K, input):
    input.sort()

    line = []
    for i in range(1, len(input)):
        line.append(input[i] - input[i-1])
        
    line.sort()
    return sum(line[:N-K])


if __name__ == '__main__':
    N = int(input())
    K = int(input())
    input = list(map(int, input().split()))

    print(step1(N, K, input))
