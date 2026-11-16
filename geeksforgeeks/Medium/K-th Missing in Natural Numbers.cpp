
class Solution:
    def findKthSmall(self, arr, k):
        low = 1
        high = max(arr) + k

        while low < high:
            mid = (low + high) // 2

            count = 0

            for x in arr:
                if x <= mid:
                    count += 1

            missing = mid - count

            if missing < k:
                low = mid + 1
            else:
                high = mid

        return low
