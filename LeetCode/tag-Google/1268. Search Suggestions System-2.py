from typing import List


class Trie:
    def __init__(self):
        self.children = {}
        self.isFinish = -1


class Solution:

    def suggestedProducts(self, products: List[str], searchWord: str) -> List[List[str]]:
        root = Trie()

        products.sort()
        for j in range(len(products)):
            product = products[j]
            current = root
            for i in range(len(product)):
                if product[i] not in current.children.keys():
                    current.children[product[i]] = Trie()
                current = current.children[product[i]]
            current.isFinish = j

        answer = []
        def dfs(i: int, current: Trie):
            if current.isFinish >= 0:
                answer[i].append(products[current.isFinish])
                if len(answer[i]) >= 3:
                    return
            for child in current.children.values():
                dfs(i, child)

        for i in range(len(searchWord)):
            answer.append([])

            check = True
            current = root
            for j in range(i+1):
                if searchWord[j] not in current.children.keys():
                    # current.children[searchWord[j]] = Trie()
                    check = False
                    break
                current = current.children[searchWord[j]]
            if check:
                dfs(i, current)
                answer[i] = answer[i][:3]

        return answer

s = Solution()

products = ["mobile","mouse","moneypot","monitor","mousepad"]
searchWord = "mouse"
print(s.suggestedProducts(products, searchWord))

products = ["bags","baggage","banner","box","cloths"]
searchWord = "bags"
print(s.suggestedProducts(products, searchWord))
