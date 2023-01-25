from typing import *
from queue import PriorityQueue

class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:

        count_dict = {}
        for word in words:
            count_dict[word] = count_dict.get(word, 0) + 1

        q = PriorityQueue(maxsize=len(words))
        for key, value in count_dict.items():
            q.put((-1*value, key))

        answer = []
        for i in range(k):
            answer.append(q.get()[1])

        return answer
        

s = Solution()

print(s.topKFrequent(["i","love","leetcode","i","love","coding"], 2))
print(s.topKFrequent(["the","day","is","sunny","the","the","the","sunny","is","is"], 4))




