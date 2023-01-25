import sys
from collections import deque
readline=sys.stdin.readline





if __name__ == '__main__':
    board = [list(map(int, readline().split())) for _ in range(3)]

    start = 0
    start_x, start_y = 0, 0
    for i in range(3):
        for j in range(3):
            start = (start << 4) + board[i][j]
            if board[i][j] == 0:
                start_x, start_y = i, j

    level = -1
    q = deque([(start_x, start_y, start)])
    visit = set()
    answer = 0
    for i in range(1, 9):
        answer += i
        answer <<= 4
    while len(q) != 0:
        level += 1
        q_size = len(q)
        for _ in range(q_size):
            x, y, current_board = q.popleft()

            if current_board == answer:
                print(level)
                exit(0)

            if y != 0:
                next_index = x*3 + (y-1)

                # 이동할 위치의 비트를 떼어낸다
                temp_board = current_board & (15 << ((8-next_index) * 4))
                # 이동할 위치에 0을 옮긴다
                next_board = current_board - temp_board
                temp_board >>= 4
                # 0이 옮겨진 장소의 숫자를 0의 위치로 옮긴다
                next_board += temp_board

                if next_board not in visit:
                    visit.add(next_board)
                    q.append((x, y - 1, next_board))

            if y != 2:
                next_index = x * 3 + (y + 1)

                # 이동할 위치의 비트를 떼어낸다
                temp_board = current_board & (15 << ((8-next_index) * 4))
                # 이동할 위치에 0을 옮긴다
                next_board = current_board - temp_board
                temp_board <<= 4
                # 0이 옮겨진 장소의 숫자를 0의 위치로 옮긴다
                next_board += temp_board

                if next_board not in visit:
                    visit.add(next_board)
                    q.append((x, y + 1, next_board))

            if x != 0:
                next_index = (x-1) * 3 + y

                # 이동할 위치의 비트를 떼어낸다
                temp_board = current_board & (15 << ((8-next_index) * 4))
                # 이동할 위치에 0을 옮긴다
                next_board = current_board - temp_board
                temp_board >>= 12
                # 0이 옮겨진 장소의 숫자를 0의 위치로 옮긴다
                next_board += temp_board

                if next_board not in visit:
                    visit.add(next_board)
                    q.append((x-1, y, next_board))

            if x != 2:
                next_index = (x+1) * 3 + y

                # 이동할 위치의 비트를 떼어낸다
                temp_board = current_board & (15 << ((8-next_index) * 4))
                # 이동할 위치에 0을 옮긴다
                next_board = current_board - temp_board
                temp_board <<= 12
                # 0이 옮겨진 장소의 숫자를 0의 위치로 옮긴다
                next_board += temp_board

                if next_board not in visit:
                    visit.add(next_board)
                    q.append((x+1, y, next_board))

    print(-1)
