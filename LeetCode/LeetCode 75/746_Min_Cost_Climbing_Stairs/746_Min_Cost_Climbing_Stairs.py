class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        cache = [None]*len(cost)

        for i in range(len(cost)):
            if i < 2:
                cache[i] = 0
                continue
            cache[i] = min(cache[i-1] + cost[i-1], cache[i-2] + cost[i-2])

        return min(cache[len(cost)-1] + cost[len(cost)-1], cache[len(cost)-2] + cost[len(cost)-2])
       