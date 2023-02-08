import sys
input=sys.stdin.readline


def step1(A, B, C):
    if B == 1:
        return A

    b1, b2 = B//2, B//2
    if B & 1:
        b2 += 1
    
    return (step1(A, b1, C) * step1(A, b2, C)) % C
   

def step2(A, B, C):
    if B == 1:
        return A

    answer = step2(A, B//2, C)

    if B & 1 == 1:
        return (answer * answer * A) % C
    return (answer * answer) % C


def step3(A, B, C):
    ret = 1
    answer = A
    while 0 < B:
        if B & 1 == 1:
            ret = (ret * answer) % C
        answer = (answer * answer) % C
        B >>= 1
    return ret % C


if __name__ == '__main__':
    A, B, C = map(int, input().split())

    print(step3(A, B, C))
