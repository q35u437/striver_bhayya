# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.position = 0
    def getDashLength(self, string):
        length = 0
        while self.position < len(string) and string[self.position] == '-':
            length += 1
            self.position += 1
        return length
    def getNumber(self, string):
        number = ''
        while self.position < len(string) and string[self.position] >= '0' and string[self.position] <= '9':
            number += string[self.position]
            self.position += 1
        return int(number)
    def buildTree(self, expectedDashLength, node, string):
        if self.position == len(string):
            return
        previousPosition = self.position
        dashLength = self.getDashLength(string)
        if dashLength < expectedDashLength:
            self.position = previousPosition
            return
        childNode = TreeNode(self.getNumber(string))
        if not node.left:
            node.left = childNode
        else:
            node.right = childNode
        self.buildTree(expectedDashLength + 1, childNode, string)
        self.buildTree(expectedDashLength + 1, childNode, string)
        
    def recoverFromPreorder(self, string: str) -> Optional[TreeNode]:
        root = TreeNode(self.getNumber(string))
        self.buildTree(1, root, string)
        self.buildTree(1, root, string)
        return root
        
