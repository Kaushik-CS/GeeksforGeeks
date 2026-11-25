
class Solution:
    def minTime(self, a, b, d, l, r):
        MOD = 10**9 + 7
        D = a - b

        def reach(x):
            k = 0 if x <= a else (x - a + D - 1) // D
            return x + 2 * b * k

        def prefix(n):
            if n <= 0:
                return 0
            q, rem = divmod(n, D)
            return D * q * (q + 1) // 2 + (q + 1) * rem

        def sum_reach(L, R):
            if L > R:
                return 0

            count = R - L + 1
            sum_x = (L + R) * count // 2

            start = max(L, a + 1)
            sum_k = 0

            if start <= R:
                sum_k = prefix(R - a) - prefix(start - a - 1)

            return sum_x + 2 * b * sum_k + count

        normal = reach(d)

        L, R = d - r, d - l

        low, high = L, R
        H = L - 1

        while low <= high:
            mid = (low + high) // 2

            if reach(mid) + 1 < normal:
                H = mid
                low = mid + 1
            else:
                high = mid - 1

        ans = 0

        if H >= L:
            ans += sum_reach(L, H)

        remaining = R - max(L, H + 1) + 1

        if remaining > 0:
            ans += remaining * normal

        return ans % MOD
