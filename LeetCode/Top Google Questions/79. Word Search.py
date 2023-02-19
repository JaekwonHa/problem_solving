from collections import defaultdict
from typing import List
import sys
sys.setrecursionlimit(10**6)

direction = [
    [0, 1],
    [1, 0],
    [0, -1],
    [-1, 0]
]

is_find = False


class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        return self.step1(board, word)
        # return self.step2(board, word)

    def step2(self, board: List[List[str]], word: str) -> bool:
        hash = defaultdict(list)
        for x in range(0, len(board)):
            for y in range(0, len(board[0])):
                hash[board[x][y]].append((x, y))

        # pruning #1
        counter = defaultdict(int)
        for i in range(len(word)):
            counter[word[i]] += 1
        for i in range(len(word)):
            if len(hash[word[i]]) < counter[word[i]]:
                return False

        # pruning #2
        if counter[word[0]] > counter[word[-1]]:
            word = word[::-1]

        visit = [[False for _ in range(len(board[0]))] for _ in range(len(board))]
        for i in range(0, len(hash[word[0]])):
            x, y = hash[word[0]][i]
            visit[x][y] = True
            if self.step2_dfs(hash, word, 1, visit, x, y):
                return True
            visit[x][y] = False

        return False

    def step2_dfs(self, hash, word, word_index, visit, x, y):
        if len(word) == word_index:
            return True

        for i in range(0, len(hash[word[word_index]])):
            nx, ny = hash[word[word_index]][i]
            # if visit[nx][ny]:
            if visit[nx][ny] or abs(x - nx) + abs(y - ny) != 1:
                continue
            visit[nx][ny] = True
            if self.step2_dfs(hash, word, word_index+1, visit, nx, ny):
                return True
            visit[nx][ny] = False
        return False

    def step1(self, board: List[List[str]], word: str) -> bool:
        hash = defaultdict(list)
        for x in range(0, len(board)):
            for y in range(0, len(board[0])):
                hash[board[x][y]].append((x, y))
        # pruning #1
        counter = defaultdict(int)
        for i in range(len(word)):
            counter[word[i]] += 1
        # for i in range(len(word)):
        #     if len(hash[word[i]]) < counter[word[i]]:
        #         return False

        # pruning #2
        if counter[word[0]] > counter[word[-1]]:
            word = word[::-1]


        global is_find
        is_find = False

        visit = [[False for _ in range(len(board[0]))] for _ in range(len(board))]
        # cost = [[[0 for _ in range(len(word))] for _ in range(len(board[0]))] for _ in range(len(board))]

        for x in range(0, len(board)):
            for y in range(0, len(board[0])):
                if word[0] == board[x][y]:
                    cost = set()
                    visit[x][y] = True
                    self.step1_dfs(board, word, 1, visit, cost, x, y)
                    visit[x][y] = False
                    if is_find:
                        break
            if is_find:
                break
        return is_find

    def step1_dfs(self, board, word, word_index, visit, cost, x, y):
        global is_find

        if len(word) == word_index:
            is_find = True
            return

        if is_find:
            return

        # remain = len(word) - word_index
        # if remain < cost[x][y]:
        #     return 0

        # if cost[x][y][word_index] == 1:
        #     return
        # cost[x][y][word_index] = 1

        # 이런식으로는 가지치기가 안된다. 반례가 있음. 지나온 경로가 달라서 이후까지 완성할 수 있는 경우가 있고, 없는 경우가 있음. 완성할 수 있는데, 이전에 완성할 수 없었던 경로가 지나가버리면 완성할 수 있어도 경로 탐색이 중지됨
        # if (x, y, word_index) in cost:
        #     return
        # cost.add((x, y, word_index))

        for dx, dy in direction:
            nx, ny = x+dx, y+dy
            if 0 <= nx < len(board) and 0 <= ny < len(board[0]) and word[word_index] == board[nx][ny] and visit[nx][ny] == False:
                visit[nx][ny] = True
                self.step1_dfs(board, word, word_index + 1, visit, cost, nx, ny)
                visit[nx][ny] = False


s = Solution()
board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
word = "ABCCED"
print(s.exist(board, word))

board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
word = "SEE"
print(s.exist(board, word))

board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
word = "ABCB"
print(s.exist(board, word))

board = [["C","A","A"],["A","A","A"],["B","C","D"]]
word = "AAB"
print(s.exist(board, word))

board = [["b","b","b","a","b","b"],["b","a","b","b","a","a"],["b","a","b","a","a","a"],["a","a","a","a","b","a"],["a","a","b","b","b","a"],["a","a","b","b","a","a"]]
word = "abbbbaabbbbb"
print(s.exist(board, word))

board = [["A","B","E"],["B","C","D"]]
word = "ABCDEB"
print(s.exist(board, word))
