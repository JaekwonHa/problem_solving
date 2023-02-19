from typing import List


class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        sortedIntervals = sorted(intervals, key=lambda x: x[0])

        answer = [[sortedIntervals[0][0], sortedIntervals[0][1]]]

        for i in range(1, len(intervals)):
            a = answer.pop()
            b = sortedIntervals[i]

            if a[0] <= b[0] <= a[1]:
                answer.append([min(a[0],b[0]), max(a[1], b[1])])
            else:
                answer.append(a)
                answer.append(b)

        return answer
