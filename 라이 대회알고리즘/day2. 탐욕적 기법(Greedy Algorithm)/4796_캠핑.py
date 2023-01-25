



def step1(L, P, V):
    answer = V//P*L + min(V%P, L)
    return answer


if __name__ == '__main__':
    index = 1
    while True:
        L, P, V = map(int, input().split())
        if L == 0 and P == 0 and V == 0:
            exit(0)
        print(f"Case {index}: {step1(L, P, V)}")
        index += 1

