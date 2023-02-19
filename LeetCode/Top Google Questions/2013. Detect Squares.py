from collections import defaultdict
from typing import List


class DetectSquares:

    def __init__(self):
        self.axis_x = defaultdict(list)
        self.axis_y = defaultdict(list)
        self.coordiToCount = defaultdict(int)

    def add(self, point: List[int]) -> None:
        self.axis_x[point[0]].append((point[0], point[1]))
        self.axis_y[point[1]].append((point[0], point[1]))
        self.coordiToCount[(point[0], point[1])] += 1

    def count(self, point: List[int]) -> int:
        answer = 0

        x1, y1 = point[0], point[1]
        for x2, y2 in self.axis_x[x1]:
            if y1 == y2:
                continue
            for x3, y3 in self.axis_y[y1]:
                if x1 == x3 or abs(x1-x3) != abs(y1-y2):
                    continue

                # for x4, y4 in self.axis_x[x3]:
                #     if y2 == y4:
                #         answer += 1
                answer += self.coordiToCount[(x3, y2)]

        return answer



# Your DetectSquares object will be instantiated and called as such:
# obj = DetectSquares()
# obj.add(point)
# param_2 = obj.count(point)


