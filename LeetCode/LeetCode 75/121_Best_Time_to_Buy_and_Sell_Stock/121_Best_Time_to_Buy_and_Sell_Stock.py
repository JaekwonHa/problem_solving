class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        min_price = prices[0]
        profit = 0
        for price in prices:
            profit = max(profit, price - min_price)
            min_price = min(min_price, price)
        return profit