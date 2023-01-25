import sys
from collections import deque

readline = sys.stdin.readline

if __name__ == '__main__':

    T = int(readline())

    for _ in range(T):
        W, H = map(int, readline().split())
        building = []
        q_fire = deque([])
        visit_fire = [[False for _ in range(W)] for _ in range(H)]
        q_humon = deque([])
        visit_humon = [[False for _ in range(W)] for _ in range(H)]
        for h in range(H):
            row = readline().replace('\n', '')
            building.append(row)
            if '@' in row:
                w = row.index('@')
                q_humon.append((h, w))
                visit_humon[h][w] = True
            if '*' in row:
                for i in range(len(row)):
                    if row[i] == '*':
                        q_fire.append((h, i))
                        visit_fire[h][i] = True

        direction = [
            (0, 1),
            (0, -1),
            (1, 0),
            (-1, 0)
        ]

        check = False
        second = 0
        while len(q_humon) != 0:
            second += 1
            q_size = len(q_fire)
            for _ in range(q_size):
                ch, cw = q_fire.popleft()
                for dh, dw in direction:
                    nh, nw = ch + dh, cw + dw
                    if 0 <= nh < H and 0 <= nw < W:
                        if building[nh][nw] == '#':
                            continue
                        if visit_fire[nh][nw]:
                            continue
                        visit_fire[nh][nw] = True
                        q_fire.append((nh, nw))
            q_size = len(q_humon)
            for _ in range(q_size):
                ch, cw = q_humon.popleft()
                for dh, dw in direction:
                    nh, nw = ch + dh, cw + dw
                    if 0 <= nh < H and 0 <= nw < W:
                        if building[nh][nw] == '#':
                            continue
                        if visit_humon[nh][nw]:
                            continue
                        if visit_fire[nh][nw]:
                            continue
                        visit_humon[nh][nw] = True
                        q_humon.append((nh, nw))
                    else:
                        check = True
                        break
            if check:
                print(second)
                break
        else:
            print("IMPOSSIBLE")
