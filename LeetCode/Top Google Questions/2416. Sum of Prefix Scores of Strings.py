from typing import List


class Trie:
    def __init__(self):
        self.storage = {}
        self.visit = 0

class Solution:
    def sumPrefixScores(self, words: List[str]) -> List[int]:

        root = Trie()
        for word in words:
            current = root
            for i in range(len(word)):
                if current.storage.get(word[i]) is None:
                    current.storage[word[i]] = Trie()
                current = current.storage[word[i]]
                current.visit += 1

        answer = []
        for word in words:
            temp = 0
            current = root
            for i in range(len(word)):
                current = current.storage[word[i]]
                temp += current.visit
            answer.append(temp)

        return answer

s = Solution()
words = ["abc","ab","bc","b"]
print(s.sumPrefixScores(words))

words = ["abcd"]
print(s.sumPrefixScores(words))
