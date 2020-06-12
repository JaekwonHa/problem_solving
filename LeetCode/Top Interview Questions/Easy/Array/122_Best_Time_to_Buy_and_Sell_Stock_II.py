from typing import List

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        buy = prices[0]
        sell = prices[0]
        result = 0
        for today in prices:
            if today < buy:
                result += buy - sell
                buy, sell = today, today
            elif today > buy:
                buy = today
        return result + buy - sell

