import sys
from collections import deque
readline=sys.stdin.readline


def step1_bfs():
    visit = [False for _ in range(N + 1)]

    count = 0
    for i in range(1, N + 1):
        if visit[i]:
            continue
        node_count, edge_count = 0, 0
        visit[i] = True
        q = deque([(i, i)])
        while len(q) != 0:
            start, current = q.popleft()
            node_count += 1
            for next in edges[current]:
                if not visit[next]:
                    edge_count += 1
                    visit[next] = True
                    q.append((start, next))
        if node_count - 1 == edge_count:
            count += 1
    return count


def step2_dfs(edges, visit, finish, current):
    visit[current] = True
    result = True
    for next in edges[current]:
        temp = True
        if visit[next] == True and finish[next] == False:
            temp = False
        if visit[next] == False:
            temp = step2_dfs(edges, visit, finish, next)
        if temp == False:
            result = False

    finish[current] = True
    return result


def step3_bfs(edges):
    visit = [False for _ in range(N + 1)]

    count = 0
    for i in range(1, N + 1):
        if visit[i]:
            continue
        node_count, edge_count = 0, 0
        visit[i] = True
        q = deque([i])
        while len(q) != 0:
            current = q.popleft()
            node_count += 1
            for next in edges[current]:
                edge_count += 1
                if not visit[next]:
                    visit[next] = True
                    q.append(next)
        if node_count - 1 == edge_count//2:
            count += 1
    return count


if __name__ == '__main__':
    idx = 1
    while True:
        N, M = map(int, readline().split())
        if N == 0 and M == 0:
            break

        edges = [[] for _ in range(N+1)]
        for _ in range(M):
            a, b = map(int, readline().split())
            edges[a].append(b)
            edges[b].append(a)

        # visit = [False for _ in range(N+1)]
        # finish = [False for _ in range(N+1)]
        #
        # count = 0
        # for i in range(1, N+1):
        #     if visit[i]:
        #         continue
        #     temp = step2_dfs(edges, visit, finish, i)
        #     if temp:
        #         count += 1

        count = step3_bfs(edges)

        if count == 0:
            print(f"Case {idx}: No trees.")
        elif count == 1:
            print(f"Case {idx}: There is one tree.")
        else:
            print(f"Case {idx}: A forest of {count} trees.")
        idx += 1
