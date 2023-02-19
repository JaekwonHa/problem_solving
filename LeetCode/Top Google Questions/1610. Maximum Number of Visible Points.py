import math
from math import atan2
from typing import List


class Solution:
    def visiblePoints(self, points: List[List[int]], angle: int, location: List[int]) -> int:

        x1, y1 = location[0], location[1]
        degrees = []
        same = 0
        for i in range(len(points)):
            x2, y2 = points[i][0], points[i][1]

            if x1 == x2 and y1 == y2:
                same += 1
                continue

            radian = atan2(y2-y1, x2-x1)
            degree = (radian * 360) / (2*math.pi)
            if degree < 0:
                degree += 360

            degrees.append(degree)
        degrees.sort()

        answer = 0
        window = []
        for i in range(len(degrees)):
            while window and degrees[i] - window[0] > angle:
                window.pop(0)
            window.append(degrees[i])
            answer = max(answer, len(window))

        for i in range(len(degrees)):
            degrees[i] += 360
            while window and degrees[i] - window[0] > angle:
                window.pop(0)
            window.append(degrees[i])
            answer = max(answer, len(window))

        return answer + same



s = Solution()
points = [[2,1],[2,2],[3,3]]
angle = 90
location = [1,1]
print(s.visiblePoints(points, angle, location))

points = [[2,1],[2,2],[3,4],[1,1]]
angle = 90
location = [1,1]
print(s.visiblePoints(points, angle, location))

points = [[1,0],[2,1]]
angle = 13
location = [1,1]
print(s.visiblePoints(points, angle, location))

points = [[1,1],[2,2],[3,3],[4,4],[1,2],[2,1]]
angle = 0
location = [1,1]
print(s.visiblePoints(points, angle, location))

points = [[0,0],[0,2]]
angle = 90
location = [1,1]
print(s.visiblePoints(points, angle, location))

points = [[30,48],[26,26],[82,91],[63,7],[3,65],[74,0],[12,26],[12,46],[57,1],[32,17],[96,37],[21,54],[20,47],[88,61],[88,44],[69,18],[21,50],[23,42],[48,43],[9,93],[45,81],[43,58],[14,82],[92,63],[16,33],[49,34],[57,50],[59,91],[59,61],[13,80],[21,81],[3,56],[30,85],[70,94],[59,27],[56,15],[4,50],[30,11],[45,82],[87,49],[12,24],[93,37],[20,38],[53,76],[28,25],[65,93],[31,86],[25,50],[63,60],[79,48],[73,58],[76,63],[99,43],[17,45],[53,9],[99,38],[10,31],[14,22],[30,53],[34,88],[37,59],[66,86],[87,58],[100,15],[48,0],[55,31],[50,19],[96,32],[40,79],[46,45],[73,47],[74,28],[72,66],[35,42],[6,89],[62,49],[67,42],[80,47],[82,31],[8,96],[97,59],[36,65],[31,48],[69,11],[12,25],[68,56],[39,62],[37,8],[58,36],[5,56],[99,94],[80,94],[64,70],[80,61],[76,47],[78,67],[41,70],[85,60],[15,40],[40,50],[20,44],[87,32],[55,90],[33,76],[76,65],[49,50],[51,10],[70,76],[1,28]]
angle = 180
location = [52,19]
print(s.visiblePoints(points, angle, location))
