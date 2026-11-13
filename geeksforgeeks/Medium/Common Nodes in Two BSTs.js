class Solution:
    def findCommon(self, r1, r2):
        def inorder(root):
            result = []
            stack = []

            while root or stack:
                while root:
                    stack.append(root)
                    root = root.left

                root = stack.pop()
                result.append(root.data)
                root = root.right

            return result

        a = inorder(r1)
        b = inorder(r2)

        i = j = 0
        ans = []

        while i < len(a) and j < len(b):
            if a[i] == b[j]:
                ans.append(a[i])
                i += 1
                j += 1
            elif a[i] < b[j]:
                i += 1
            else:
                j += 1

        return ans