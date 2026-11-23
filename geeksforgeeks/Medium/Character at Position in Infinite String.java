
class Solution:
    def posInfinite(self, s, pos):
        n = len(s)

        lengths = []
        length = n
        i = 1

        while length < pos:
            lengths.append((length, i))
            length = 2 * length + i
            i += 1

        while lengths:
            old_length, step = lengths.pop()

            if pos <= old_length:
                continue

            elif pos <= old_length + step:
                return '$'

            else:
                pos = 2 * old_length + step - pos + 1

        return s[pos - 1]
