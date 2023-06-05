from typing import List




class Solution:

    def suggestedProducts(self, products: List[str], searchWord: str) -> List[List[str]]:
        products.sort()

        answer = []
        for i in range(len(searchWord)):
            answer.append([])
            prefix = searchWord[:i+1]
            left, right = 0, len(products)-1
            while left <= right:
                mid = (left + right) // 2
                if products[mid] >= prefix:
                    right = mid - 1
                else:
                    left = mid + 1
            j = 0
            while left + j < len(products) and j < 3:
                if prefix == products[left + j][:i+1]:
                    answer[i].append(products[left+j])
                j += 1
        return answer



s = Solution()

products = ["mobile","mouse","moneypot","monitor","mousepad"]
searchWord = "mouse"
print(s.suggestedProducts(products, searchWord))

products = ["bags","baggage","banner","box","cloths"]
searchWord = "bags"
print(s.suggestedProducts(products, searchWord))
