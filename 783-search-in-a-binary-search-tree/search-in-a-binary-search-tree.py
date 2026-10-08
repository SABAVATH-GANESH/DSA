# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    ans=[]
    def searchBST(self, root, val):
        """
        :type root: Optional[TreeNode]
        :type val: int
        :rtype: Optional[TreeNode]
        """
        temp=root
        
        while temp is not None:
            if temp.val==val:
                return temp
            elif temp.val > val:
                temp=temp.left
            else:
                temp=temp.right
        
       
        return None
    