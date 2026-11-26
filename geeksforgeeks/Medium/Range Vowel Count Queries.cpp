
class Solution:
    def countVowels(self, s, queries):
        prefix = [0] * (len(s) + 1)
        vowels = "aeiou"

        for i in range(len(s)):
            prefix[i + 1] = prefix[i]

            if s[i] in vowels:
                prefix[i + 1] += 1

        ans = []

        for l, r in queries:
            ans.append(prefix[r + 1] - prefix[l])

        return ans
