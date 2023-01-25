





def step1(N, S, li, index, partial_sum, count):
    if index == N:
        return 1 if (partial_sum == S and count != 0) else 0

    return step1(N, S, li, index+1, partial_sum+li[index], count+1) + step1(N, S, li, index+1, partial_sum, count)


if __name__ == '__main__':
    N, S = map(int, input().split())
    li = list(map(int, input().split()))

    answer = step1(N, S, li, 0, 0, 0)
    
    print(answer)


