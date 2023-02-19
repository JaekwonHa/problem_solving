class Node:
    def __init__(self, key: int, value, prev, next):
        self.key = key
        self.value = value
        self.prev = prev
        self.next = next


class LRUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.hash = dict()
        self.head = Node(-1, "head", None, None)
        self.tail = Node(-1, "tail", None, None)
        self.head.next, self.tail.prev = self.tail, self.head

    def get(self, key: int) -> int:
        # map에서 가져온다. map에서 가져온 node를 가장 앞에 배치한다
        node = self.hash.get(key, None)
        if node is None:
            return -1

        node.prev.next, node.next.prev = node.next, node.prev
        node.prev, node.next = self.head, self.head.next
        node.prev.next = node
        node.next.prev = node
        return node.value

    def put(self, key: int, value: int) -> None:
        # map에서 가져온다. map에서 가져온 node를 가장 앞에 배치한다
        # map에 없다면 node를 만들고 가장 앞에 배치한다
        # capacity에 도달했다면, tail node를 지운다
        node = self.hash.get(key, None)
        if node is None:
            node = Node(key, value, self.head, self.head.next)
            node.prev.next = node
            node.next.prev = node
        else:
            node.prev.next, node.next.prev = node.next, node.prev
            node.prev, node.next = self.head, self.head.next
            node.prev.next = node
            node.next.prev = node
            node.value = value

        self.hash[key] = node

        if len(self.hash) > self.capacity:
            temp = self.tail.prev
            if temp.key >= 0:
                del self.hash[temp.key]
            self.tail.prev.prev.next, self.tail.prev = self.tail, self.tail.prev.prev


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(2)
# obj.put(1, 1)
# obj.put(2, 2)
# print(obj.get(1))
# obj.put(3, 3)
# print(obj.get(2))
# obj.put(4, 4)
# print(obj.get(1))
# print(obj.get(3))
# print(obj.get(4))

obj = LRUCache(2)
obj.put(2, 1)
obj.put(1, 1)
obj.put(2, 3)
obj.put(4, 1)
print(obj.get(1))
print(obj.get(2))
