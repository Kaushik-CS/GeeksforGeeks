
class Solution:
    def findPairs(self, arr):
        n = len(arr)
        mp = {}
        ans = None

        for i in range(n):
            for j in range(i + 1, n):
                s = arr[i] + arr[j]

                if s in mp:
                    for a, b in mp[s]:
                        if b < i:
                            candidate = [a, b, i, j]

                            if ans is None or candidate < ans:
                                ans = candidate

                mp.setdefault(s, []).append((i, j))

        return ans if ans is not None else [-1, -1, -1, -1]
