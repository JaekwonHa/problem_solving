import sys
sys.setrecursionlimit(10**6)


limit = 0

class Solution:
    def racecar(self, target: int) -> int:
        global limit
        limit = max(100, target + (target//2) + 1)
        
        visit = [[[False for _ in range(2)] for _ in range(limit+1)] for _ in range(limit+1)]
        used = [limit for _ in range(limit+1)]

        visit[0][1][0] = True
        used[target] = self.backtracking(target, visit, used, 0, 1, 0, 0)
        return used[target] if used[target] != limit else -1

    def backtracking(self, target, visit, used, pos, speed, direction, step):
        global limit
        if pos < 0:
            return limit
        if pos > limit:
            return limit
        if used[pos] <= step:
            return used[pos]
        if pos == target:
            used[pos] = min(used[pos], step)
            return used[pos]


        if direction == 0:
            if pos+speed <= limit and 2*speed <= limit and not visit[pos+speed][2*speed][0]:
                visit[pos + speed][2 * speed][0] = True
                used[pos] = min(used[pos], self.backtracking(target, visit, used, pos + speed, 2 * speed, 0, step + 1))
                visit[pos + speed][2 * speed][0] = False

            if not visit[pos][1][1]:
                visit[pos][1][1] = True
                used[pos] = min(used[pos], self.backtracking(target, visit, used, pos, 1, 1, step + 1))
                visit[pos][1][1] = False

        else:
            if not visit[pos][1][0]:
                visit[pos][1][0] = True
                used[pos] = min(used[pos], self.backtracking(target, visit, used, pos, 1, 0, step + 1))
                visit[pos][1][0] = False

            if pos-speed > 0 and 2*speed <= limit and not visit[pos-speed][2*speed][1]:
                visit[pos - speed][2 * speed][1] = True
                used[pos] = min(used[pos], self.backtracking(target, visit, used, pos - speed, 2 * speed, 1, step + 1))
                visit[pos - speed][2 * speed][1] = False

        return used[pos]


s = Solution()
target = 1
print(s.racecar(target))
target = 2
print(s.racecar(target))
target = 3
print(s.racecar(target))

target = 6
print(s.racecar(target))

target = 10
print(s.racecar(target))
target = 100
print(s.racecar(target))
target = 330
print(s.racecar(target))
target = 1000
print(s.racecar(target))
