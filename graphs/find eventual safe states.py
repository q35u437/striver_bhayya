class Solution:
    def dfs(self, currentNode, graph, isSafe, visited):
        visited[currentNode] = True
        mightBeSafe = True
        for neighbour in graph[currentNode]:
            if not visited[neighbour]:
                mightBeSafe = mightBeSafe and self.dfs(neighbour, graph, isSafe, visited)
            else:
                mightBeSafe = mightBeSafe and isSafe[neighbour]
        isSafe[currentNode] = mightBeSafe
        return isSafe[currentNode]
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        number = len(graph)
        isSafe = [False for i in range(number)]
        visited = [False for i in range(number)]
        for i in range(number):
            if not visited[i]:
                self.dfs(i, graph, isSafe, visited)
        answer = []
        for i in range(number):
            if isSafe[i]:
                answer.append(i)
        return answer
