
class Solution:
    def findPairs(self, arr):
        n = len(arr)
        mp = {}

        for i in range(n):
            for j in range(i + 1, n):
                s = arr[i] + arr[j]

                if s in mp:
                    a, b = mp[s]

                    if b < i:
                        return [a, b, i, j]

                else:
                    mp[s] = (i, j)

        # Check overlapping pairs by retaining alternative pairs
        # is necessary, so use the complete pair approach below.

        return [-1, -1, -1, -1]
