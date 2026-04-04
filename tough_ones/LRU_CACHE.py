class Node:
    def __init__(self, left, right, key, value):
        self.key = key
        self.value = value
        self.left = left
        self.right = right
class LRUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.headNode = Node(None, None, 0, 0)
        self.tailNode = Node(None, None, -1, -1)
        self.headNode.right = self.tailNode
        self.tailNode.left = self.headNode
        self.dictionary = {}

    def get(self, key: int) -> int:
        if key in self.dictionary:
            # if self.headNode.right is self.dictionary[key]:
            #     return self.dictionary[key].value
            rightNode, leftNode = self.dictionary[key].right, self.dictionary[key].left
            leftNode.right, rightNode.left = rightNode, leftNode
            head = self.headNode.right
            self.dictionary[key].right = head
            self.dictionary[key].left = self.headNode
            head.left = self.dictionary[key]
            self.headNode.right = self.dictionary[key]
            return self.dictionary[key].value
        else:
            return -1
    def put(self, key: int, value: int) -> None:
        if key in self.dictionary:
            self.dictionary[key].value = value
            rightNode, leftNode = self.dictionary[key].right, self.dictionary[key].left
            leftNode.right, rightNode.left = rightNode, leftNode
            head = self.headNode.right
            self.dictionary[key].right = head
            self.dictionary[key].left = self.headNode
            head.left = self.dictionary[key]
            self.headNode.right = self.dictionary[key]
            return
        if len(self.dictionary) < self.capacity:
            self.dictionary[key] = Node(None, None, key, value)
            head = self.headNode.right
            self.dictionary[key].right = head
            self.dictionary[key].left = self.headNode
            head.left = self.dictionary[key]
            self.headNode.right = self.dictionary[key]
        else:
            tail = self.tailNode.left
            tail.left.right = tail.right
            tail.right.left = tail.left
            self.dictionary.pop(tail.key)
            self.dictionary[key] = Node(None, None, key, value)
            head = self.headNode.right
            self.dictionary[key].right = head
            self.dictionary[key].left = self.headNode
            head.left = self.dictionary[key]
            self.headNode.right = self.dictionary[key]
# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
