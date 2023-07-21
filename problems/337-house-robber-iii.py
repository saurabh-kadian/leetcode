# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from functools import lru_cache
class Solution:
    @lru_cache(None)
    def solve(self, node: Optional[TreeNode], canRob: bool) -> int:
        if node is None:
            return 0
        
        lnr = self.solve(node.left, True)
        rnr = self.solve(node.right, True)
        if canRob:
            lq = self.solve(node.left, False)
            rq = self.solve(node.right, False)
            return max(lq+rq+node.val, lnr+rnr)
        return lnr+rnr

    def rob(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0
        lq = self.solve(root.left, False)
        rq = self.solve(root.right, False)
        lnr = self.solve(root.left, True)
        rnr = self.solve(root.right, True)
        return max(lq+rq+root.val, lnr+rnr)
