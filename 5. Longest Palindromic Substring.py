class Solution:
    def performManachers(self, transformed, d_odd):
        left = 0
        right = 1
        length = len(transformed)
        for index in range(length):
            #check if the index falls within our latest know pallindrome
            if index <= right:
                d_odd[index] = min(right - index, d_odd[left + (right - index)])
            while index - d_odd[index] >= 0 and index + d_odd[index] < length and transformed[index - d_odd[index]] == transformed[index + d_odd[index]]:
                d_odd[index] += 1
            if index + d_odd[index] > right:
                left = index - d_odd[index]
                right = index + d_odd[index]


    def longestPalindrome(self, s: str) -> str:
        transformed = "#" + "#".join(s) + "#"
        d_odd = [
            0 for i in range(len(transformed))
        ]
        self.performManachers(transformed,d_odd)
        bestLength = bestIndex = -1
        for index, length in enumerate(d_odd):
            original_index = (index - (length - 1)) // 2
            if (length - 1) > bestLength:
                bestLength = (length - 1)
                bestIndex = original_index
        return s[bestIndex: bestIndex + bestLength]
