# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def constructFromPrePost(self, preorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        postOrderIndeces = dict([(postorder[index], index) for index in range(len(preorder))])
        def buildTree(preStart, preEnd, postStart, postEnd):
            if preStart > preEnd:
                return None
            if preStart == preEnd:
                return TreeNode(preorder[preStart])
            rootValue = preorder[preStart]
            leftNodeValue = preorder[preStart + 1]
            leftNodeIndexInPost = postOrderIndeces[leftNodeValue]
            leftSubTreeSize = leftNodeIndexInPost - postStart + 1
            root = TreeNode(rootValue)
            root.left = buildTree(preStart + 1, preStart + leftSubTreeSize, postStart, leftNodeIndexInPost)
            root.right = buildTree(preStart + leftSubTreeSize + 1, preEnd ,leftNodeIndexInPost + 1, postEnd - 1)
            return root
        return buildTree(0, len(preorder)-1, 0, len(postorder)-1)
