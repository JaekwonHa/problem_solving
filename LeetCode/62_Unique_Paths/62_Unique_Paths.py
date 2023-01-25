class Solution:
    dp = None
    def dfs(self, i, j) -> int:
        if i == 0 or j == 0:
            self.dp[i][j] = 1
            return self.dp[i][j]
       
        if self.dp[i][j] != 0:
            return self.dp[i][j]
        
        self.dp[i][j] = self.dfs(i, j-1) + self.dfs(i-1, j)
        return self.dp[i][j]

    def uniquePaths(self, m: int, n: int) -> int:
        self.dp = [[0 for _ in range(n)] for _ in range(m)]

        return self.dfs(m-1, n-1)

s = Solution()


answer = s.uniquePaths(3, 7)
print(answer)
