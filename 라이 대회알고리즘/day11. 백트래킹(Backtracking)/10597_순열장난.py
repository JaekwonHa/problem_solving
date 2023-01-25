import sys
sys.setrecursionlimit(10**6)

readline = sys.stdin.readline


def step1(idx):
    global N, numbers, answer, is_find
    if is_find:
        return

    if len(answer) == N or len(numbers) <= idx:
        if set(answer) == set(range(1, N + 1)):
            print(*answer)
            is_find = True
        return

    temp = numbers[idx]
    if temp not in answer:
        answer.append(int(temp))
        step1(idx + 1)
        answer.pop()

    if 9 < N and idx + 2 <= len(numbers):
        temp = numbers[idx:idx + 2]
        if temp[0] != '0' and int(temp) <= N and temp not in answer:
            answer.append(int(temp))
            step1(idx + 2)
            answer.pop()


def step2(idx, visit):
    global N, numbers, answer, is_find
    if is_find:
        return

    if len(answer) == N or len(numbers) <= idx:
        if set(answer) == set(range(1, N + 1)):
            print(*answer)
            is_find = True
        return

    temp = int(numbers[idx])
    if not visit[temp]:
        answer.append(int(temp))
        visit[temp] = True
        step1(idx + 1, visit)
        visit[temp] = False
        answer.pop()

    if 9 < N and numbers[idx] != '0' and idx + 2 <= len(numbers):
        temp = int(numbers[idx:idx + 2])
        if temp <= N and not visit[temp]:
            answer.append(int(temp))
            visit[temp] = True
            step1(idx + 2, visit)
            visit[temp] = False
            answer.pop()


if __name__ == '__main__':
    numbers = readline().replace('\n', '')

    N = min(9, len(numbers)) if len(numbers) < 10 else (len(numbers) - 9) // 2 + 9

    answer = []
    # step1(0)

    visit = [False for _ in range(N+1)]
    is_find = False
    step2(0, visit)
