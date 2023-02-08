import sys
readline=sys.stdin.readline

sys.setrecursionlimit(10**6)

adj = None
visit = [False] * 100001
is_cycle = False

def step1(u):
    visit[u] = True

    global is_cycle

    answer = 1
    for v in adj[u]:
        if visit[v] == False:
            answer += step1(v)
            break
        else:
            is_cycle = True
            break
    return answer


if __name__ == '__main__':
    N, M, P = map(int, readline().split())

    adj = [[] for _ in range(M+1)]

    for _ in range(N):
        u, v = map(int, readline().split())
        adj[v].append(u)

    answer = step1(P) - 1
    print(-1) if is_cycle else print(answer)
