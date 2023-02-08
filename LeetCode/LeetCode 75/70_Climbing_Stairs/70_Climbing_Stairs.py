cache = {}

class Solution:
    def climbStairs(self, n: int) -> int:
        if n <= 2:
            return n

        if cache.get(n):
            return cache[n]

        cache[n] = self.climbStairs(n-1) + self.climbStairs(n-2)
        return cache[n]
