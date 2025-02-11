class Solution:
    def removeOccurrences(self, s: str, part: str) -> str:
        stack = []
        index = 0
        while index < len(s):
            stack.append(s[index])
            if len(stack) >= len(part):
                length = len(stack)
                if ''.join(stack[length - len(part):length]) == part:
                    ii = length - len(part)
                    while ii < length:
                        stack.pop()
                        ii+=1
            index += 1
        return ''.join(stack)
