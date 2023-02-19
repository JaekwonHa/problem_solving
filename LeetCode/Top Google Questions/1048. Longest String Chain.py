from collections import defaultdict
from typing import List


class Solution:
    def longestStrChain(self, words: List[str]) -> int:

        lengthToWord = defaultdict(list)
        for word in words:
            lengthToWord[len(word)].append(word)

        edges = defaultdict(list)
        for length in sorted(lengthToWord.keys()):
            for node in lengthToWord[length]:
                for next in lengthToWord[length+1]:
                    if self.isPredecessor(node, next):
                        edges[node].append(next)

        answer = 0
        visit = defaultdict(int)
        for word in words:
            answer = max(answer, self.dfs(visit, edges, word))
        return answer

    def isPredecessor(self, word1, word2) -> bool:
        miss = 0
        i, j = 0, 0
        while i < len(word1) and j < len(word2) and miss <= 1:
            if word1[i] == word2[j]:
                i += 1
                j += 1
            else:
                miss += 1
                j += 1

        if i == len(word1) and j == len(word2) and miss == 1:
            return True
        if i == len(word1) and j == len(word2)-1 and miss == 0:
            return True
        return False

    def dfs(self, visit, edges, current):
        if visit[current] > 0:
            return visit[current]

        length = 1

        for next in edges[current]:
            length = max(length, self.dfs(visit, edges, next)+1)

        visit[current] = length
        return length


s = Solution()
words = ["a","b","ba","bca","bda","bdca"]
print(s.longestStrChain(words))

words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
print(s.longestStrChain(words))

words = ["abcd","dbqca"]
print(s.longestStrChain(words))
