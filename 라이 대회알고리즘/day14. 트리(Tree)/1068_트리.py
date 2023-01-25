import sys
readline=sys.stdin.readline


def dfs(edges, current):
    global K
    if current == K:
        return 0
    if len(edges[current]) == 0:
        return 1

    if len(edges[current]) == 1 and edges[current][0] == K:
        return 1

    count = 0
    for next in edges[current]:
        if next == K:
            continue
        count += dfs(edges, next)
    return count


if __name__ == '__main__':
    N = int(readline())
    numbers = list(map(int, readline().split()))
    K = int(readline())

    edges = [[] for _ in range(N)]
    start = []
    for i in range(N):
        parent = numbers[i]
        if parent == -1:
            start.append(i)
            continue
        # if i == K:
        #     continue
        edges[parent].append(i)

    root_count = 0
    for s in start:
        root_count += dfs(edges, s)
        break
    # delete_count = dfs(edges, K)
    # print(root_count - delete_count)

    # print(dfs(edges, start))

    print(root_count)


