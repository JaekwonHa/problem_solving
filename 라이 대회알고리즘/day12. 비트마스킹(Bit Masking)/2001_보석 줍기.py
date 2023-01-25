import sys
sys.setrecursionlimit(10**6)
from collections import deque

readline = sys.stdin.readline


def dfs(edges, K, diamonds, count, DP, used, idx, first):
    if first == False and 1 == idx:
        return count

    if DP[used] != -1:
        return DP[used]

    answer = 0
    for j, weight in edges[idx]:
        if weight < count:
            continue
        if j in diamonds and used & (1 << diamonds.index(j)) == 0:
            used |= (1 << diamonds.index(j))
            answer = max(answer, dfs(edges, K, diamonds, count + 1, DP, used, j, False))
            used &= ~(1 << diamonds.index(j))
        answer = max(answer, dfs(edges, K, diamonds, count, DP, used, j, False))

    DP[used] = answer
    return answer


def step1():
    N, M, K = map(int, readline().split())
    diamonds = [int(readline()) for _ in range(K)]
    edges = [[] for _ in range(N + 1)]
    for _ in range(M):
        a, b, c = map(int, readline().split())
        edges[a].append((b, c))
        edges[b].append((a, c))

    DP = [-1 for _ in range(1 << 14)]
    visit = 0
    count = 0
    answer = 0
    if 1 in diamonds:
        K -= 1
        del diamonds[diamonds.index(1)]
        answer = max(answer, dfs(edges, K, diamonds, count, DP, visit, 1, True))
    else:
        answer = max(answer, dfs(edges, K, diamonds, count, DP, visit, 1, True))

    print(answer)


def step2():
    N, M, K = map(int, readline().split())
    diamonds = [int(readline()) for _ in range(K)]
    for i in range(K):
        diamonds[i] -= 1
    edges = [[] for _ in range(N + 1)]
    for _ in range(M):
        a, b, c = map(int, readline().split())
        edges[a-1].append((b-1, c))
        edges[b-1].append((a-1, c))

    answer = 0
    visit = [[[False for _ in range(1 << K)] for _ in range(14)] for _ in range(N)]
    q = deque([(0, 0, 0)])
    while len(q) != 0:
        i, count, used = q.popleft()

        if i == 0:
            answer = max(answer, count + (1 if 0 in diamonds else 0))

        for j, weight in edges[i]:
            if weight < count:
                continue
            # 보석을 줍는다
            if j != 0 and j in diamonds:
                used |= (1 << j)
                count += 1
                if not visit[j][count][used]:
                    visit[j][count][used] = True
                    q.append((j, count, used))
                count -= 1
                used &= ~(1 << j)
            # 보석을 줍지 않는다
            if not visit[j][count][used]:
                visit[j][count][used] = True
                q.append((j, count, used))
    print(answer)


def step3():
    N, M, K = map(int, readline().split())
    diamonds = [int(readline()) for _ in range(K)]
    edges = [[] for _ in range(N+1)]
    for _ in range(M):
        a, b, c = map(int, readline().split())
        edges[a].append((b, c))
        edges[b].append((a, c))

    answer = 0
    visit = [[False for _ in range(1 << 14)] for _ in range(101)]
    visit[1][0] = True
    q = deque([(1, 0, 0)])
    # if 1 in diamonds:
    #     diamond = diamonds.index(1)
    #     visit[1][(1 << diamond)] = True
    #     q.append((1, 1, (1 << diamond)))

    while len(q) != 0:
        i, count, used = q.popleft()
        # count = 0
        # for j in range(K):
        #     if used & (1 << j) != 0:
        #         count += 1

        if i == 1:
            answer = max(answer, count + (1 if 1 in diamonds else 0))
            # answer = max(answer, count)

        for j, weight in edges[i]:
            if weight < count:
                continue
            # 보석을 줍는다
            if j != 1 and j in diamonds:
            # if j in diamonds:
                diamond = diamonds.index(j)
                if not visit[j][used | (1 << diamond)] and used & (1 << diamond) == 0:
                    visit[j][used | (1 << diamond)] = True
                    q.append((j, count+1, used | (1 << diamond)))
            # 보석을 줍지 않는다
            if not visit[j][used]:
                visit[j][used] = True
                q.append((j, count, used))
    print(answer)


if __name__ == '__main__':
    # step1()
    # step2()
    step3()
