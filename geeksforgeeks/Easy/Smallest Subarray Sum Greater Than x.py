
class Solution:
    def smallestSubWithSum(self, arr, x):
        left = 0
        curr_sum = 0
        ans = float('inf')

        for right in range(len(arr)):
            curr_sum += arr[right]

            while curr_sum > x:
                ans = min(ans, right - left + 1)
                curr_sum -= arr[left]
                left += 1

        return 0 if ans == float('inf') else ans
