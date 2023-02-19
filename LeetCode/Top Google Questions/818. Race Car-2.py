from collections import deque


class Solution:
    def racecar(self, target: int) -> int:

        q = deque([(0, 0, +1)])

        while q:
            step, pos, speed = q.popleft()
            if pos == target:
                return step

            next_pos, next_speed = pos + speed, 2 * speed
            q.append((step+1, next_pos, next_speed))

            if (target < next_pos and next_speed > 0) or (next_pos < target and next_speed < 0):
                q.append((step+1, pos, -1 if next_speed > 0 else 1))




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
