from typing import List


class Solution:
    def suggestedProducts(self, products: List[str], searchWord: str) -> List[List[str]]:
        products.sort()
        answer = []
        for i in range(len(searchWord)):
            temp = []
            partial = searchWord[:i+1]
            find = False
            for product in products:
                if i < len(product) and partial == product[:i+1]:
                    temp.append(product)
                    find = True
                elif find:
                    break
                if len(temp) >= 3:
                    break
            answer.append(temp)

        return answer

s = Solution()

products = ["mobile","mouse","moneypot","monitor","mousepad"]
searchWord = "mouse"
print(s.suggestedProducts(products, searchWord))
