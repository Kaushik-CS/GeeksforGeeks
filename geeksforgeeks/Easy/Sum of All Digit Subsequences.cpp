
class Solution:
    def subsequenceSum(self, s):
        MOD = 10**9 + 7

        n = len(s)
        digit_sum = sum(int(digit) for digit in s)

        return (digit_sum * pow(2, n - 1, MOD)) % MOD
