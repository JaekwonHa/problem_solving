class Solution:

    cache = {}

    def fib(self, n: int) -> int:
        if n == 0 or n == 1:
            return n

        if self.cache.get(n):
            return self.cache.get(n)

        self.cache[n] = self.fib(n-1) + self.fib(n-2)
        return self.cache.get(n)
