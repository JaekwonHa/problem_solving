from collections import defaultdict, deque
from typing import List


class Solution:
    def countBattleships(self, board: List[List[str]]) -> int:
        visit = [[False for _ in range(len(board[0]))] for _ in range(len(board))]
        direction = [
            (0, 1),
            (0, -1),
            (1, 0),
            (-1, 0)
        ]

        answer = 0
        q = deque([])
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] == "X" and not visit[i][j]:
                    answer += 1

                    visit[i][j] = True
                    q.append((i, j))
                    while q:
                        x, y = q.popleft()
                        for dx, dy in direction:
                            nx, ny = x + dx, y + dy
                            if 0 <= nx < len(board) and 0 <= ny < len(board[0]):
                                if board[nx][ny] == "X" and not visit[nx][ny]:
                                    visit[nx][ny] = True
                                    q.append((nx, ny))

        return answer
