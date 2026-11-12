
class Solution:
    def minDiff(self, root, k):
        ans = float('inf')

        def solve(node):
            nonlocal ans

            if node is None:
                return

            ans = min(ans, abs(node.data - k))

            solve(node.left)
            solve(node.right)

        solve(root)
        return ans
