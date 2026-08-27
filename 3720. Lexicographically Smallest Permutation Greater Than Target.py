class Solution:
    def we_can_find_another_weaker_character(self, freq, target):
        substring = ''
        for k in range(25,-1,-1):
            if freq[k] > 0:
                substring += chr(97 + k) * freq[k]
        return substring > target
    def lexGreaterPermutation(self, s: str, target: str) -> str:
        freq = [
            0 for i in range(26)
        ]
        for char in s:
            determined_index = ord(char) - 97
            freq[determined_index] += 1
        answer = ""
        for index, character in enumerate(target):
            checking_index = ord(character) - 97
            if freq[checking_index] > 0:
                #since we have found a character that is equal to the charater at index in target. 
                #this can help us achieving the smallest greatest string than target but before that
                #we have to make sure that by adding this character we can still find a lexicographically smallest possible string with 
                #out remaining set of characters
                freq[checking_index] -= 1
                if self.we_can_find_another_weaker_character(freq, target[index+1:]):
                    answer += character 
                    continue
                freq[checking_index] += 1
            #since we tried seeing that by bypassing the character at index in target
            #if we can find the greater one and we failed, adhocly first add the character just greater than our current character
            #and then add remaining all characters.
            for ii in range(checking_index + 1, 26):
                if freq[ii] > 0:
                    answer += chr(97 + ii)
                    freq[ii] -= 1
                    break
            else:
                return ""
            for ii in range(26):
                answer += (chr(97+ii) * (freq[ii]))
            return answer
