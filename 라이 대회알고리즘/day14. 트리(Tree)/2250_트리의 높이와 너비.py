import sys
from collections import deque
sys.setrecursionlimit(10**6)
readline=sys.stdin.readline


inorder_result = []


def dfs_inorder(edges, current):
    if current == -1:
        return

    if len(edges[current]) == 0:
        inorder_result.append(current)
        return

    dfs_inorder(edges, edges[current][0])
    inorder_result.append(current)
    dfs_inorder(edges, edges[current][1])


if __name__ == '__main__':
    N = int(readline())

    root_check = [0 for _ in range(N+1)]
    edges = [[] for _ in range(N+1)]
    for _ in range(N):
        a, b, c = map(int, readline().split())
        edges[a].append(b)
        edges[a].append(c)
        root_check[a] += 1
        if b != -1:
            root_check[b] += 1
        if c != -1:
            root_check[c] += 1

    start = 0
    for i in range(1, N+1):
        if root_check[i] == 1:
            start = i
            break

    coordi_x = [[] for _ in range(N+1)]
    coordi_y = [0 for _ in range(N+1)]

    # x 좌표 구하기. level order
    q = deque([start])
    level = 0
    while len(q) != 0:
        q_size = len(q)
        level += 1
        for _ in range(q_size):
            current = q.popleft()
            coordi_x[level].append(current)
            for next in edges[current]:
                if next != -1:
                    q.append(next)

    # y 좌표 구하기. in order
    dfs_inorder(edges, start)
    for i in range(N):
        coordi_y[inorder_result[i]] = i+1

    answer_width = 0
    answer_level = 0
    for l in range(1, level+1):
        if len(coordi_x[l]) == 0:
            continue
        width = coordi_y[coordi_x[l][-1]] - coordi_y[coordi_x[l][0]] + 1
        if answer_width < width:
            answer_width = width
            answer_level = l

    print(answer_level, answer_width)
