from collections import defaultdict

class Solution:
    def findPairs(self, arr):
        n = len(arr)
        mp = defaultdict(list)
        best = [-1, -1, -1, -1]

        for c in range(n):
            for d in range(c + 1, n):
                s = arr[c] + arr[d]
                lst = mp[s]

                # earliest stored pair sharing no index with (c, d)
                for a, b in lst:
                    if a != c and a != d and b != c and b != d:
                        cand = [a, b, c, d]
                        if best[0] == -1 or cand < best:
                            best = cand
                        break

                lst.append((c, d))

        return best