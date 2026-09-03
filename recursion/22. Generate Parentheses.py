class Solution:
    def getAnswer(self, string, counter, length, pairs, answer):
        if 2*pairs == length:
            if counter == 0:
                answer.append(string)
            return
        self.getAnswer(string + '(', counter + 1, length + 1, pairs, answer)
        if counter > 0:
            self.getAnswer(string + ')', counter - 1, length + 1, pairs, answer)

    def generateParenthesis(self, n: int) -> List[str]:
        answer = []
        self.getAnswer("", 0, 0, n, answer)
        return answer
