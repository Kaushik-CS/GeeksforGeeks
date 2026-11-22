
class Solution:
    def longestSubarrayDivK(self, arr, k):
        mp = {0: -1}
        prefix_sum = 0
        max_len = 0

        for i in range(len(arr)):
            prefix_sum += arr[i]
            rem = prefix_sum % k

            if rem in mp:
                max_len = max(max_len, i - mp[rem])
            else:
                mp[rem] = i

        return max_len
