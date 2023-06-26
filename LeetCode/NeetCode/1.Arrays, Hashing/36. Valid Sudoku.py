from typing import List

class Solution:
    def isValid(self, line: List[str]) -> bool:
        hash = set()
        for e in line:
            if e != '.':
                if e in hash:
                    return False
                else:
                    hash.add(e)
        return True


    def isValidSudoku(self, board: List[List[str]]) -> bool:
        # vertical
        for i in range(0, 9):
            line = []
            for j in range(0, 9):
                line.append(board[j][i])
            result = self.isValid(line)
            if not result:
                return False

        # horizontal
        for i in range(0, 9):
            line = board[i]
            result = self.isValid(line)
            if not result:
                return False

        # sub-boxes
        for i in range(0, 9):
            x = i % 3 * 3
            y = i // 3 * 3
            line = []
            for j in range(0, 3):
                for k in range(0, 3):
                    line.append(board[x+j][y+k])
            result = self.isValid(line)
            if not result:
                return False

        return True


s = Solution()

board = [["5", "3", ".", ".", "7", ".", ".", ".", "."],
         ["6", ".", ".", "1", "9", "5", ".", ".", "."],
         [".", "9", "8", ".", ".", ".", ".", "6", "."],
         ["8", ".", ".", ".", "6", ".", ".", ".", "3"],
         ["4", ".", ".", "8", ".", "3", ".", ".", "1"],
         ["7", ".", ".", ".", "2", ".", ".", ".", "6"],
         [".", "6", ".", ".", ".", ".", "2", "8", "."],
         [".", ".", ".", "4", "1", "9", ".", ".", "5"],
         [".", ".", ".", ".", "8", ".", ".", "7", "9"]]
print(s.isValidSudoku(board))
