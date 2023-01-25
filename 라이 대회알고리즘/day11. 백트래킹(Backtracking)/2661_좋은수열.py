import sys

sys.setrecursionlimit(10 ** 6)

readline = sys.stdin.readline


def valid(partial):
    left, right = partial[:len(partial) // 2], partial[len(partial) // 2:]
    if left == right:
        return False
    return True


def step1():
    global N, answer
    if len(answer) == N:
        print("".join(list(map(str, answer))))
        exit(0)

    for i in range(1, 4):
        answer.append(i)
        if 2 <= len(answer):
            l = len(answer)
            is_valid = True
            for j in range(2, len(answer)+1, 2):
                if not valid(answer[l-j:]):
                    is_valid = False
                    break
            if is_valid:
                step1()
        else:
            step1()
        answer.pop()


if __name__ == '__main__':
    N = int(readline())

    answer = []
    step1()
