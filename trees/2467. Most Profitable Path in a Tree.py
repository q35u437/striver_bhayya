class Solution:
    def mostProfitablePath(self, edges: List[List[int]], bob: int, amount: List[int]) -> int:
        adj = [list() for i in range(len(edges)+1)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        def doBFSFromBobToRoot(node, parent, path):
            path.append(node)
            if node == 0:
                return True
            for neighbour in adj[node]:
                if neighbour != parent:
                    if doBFSFromBobToRoot(neighbour, node, path):
                        return True
            path.pop()
        
        getBobToRootPath = []
        doBFSFromBobToRoot(bob, -1, getBobToRootPath)
        middle = len(getBobToRootPath) // 2
        for i in range(middle):
            amount[getBobToRootPath[i]] = 0
        if (len(getBobToRootPath)) % 2:
            amount[getBobToRootPath[middle]] //= 2
        def dfs(node, parent, totalPathCost):
            totalPathCost += amount[node]
            if len(adj[node]) == 1 and adj[node][0] == parent:
                nonlocal answer
                answer = max(answer, totalPathCost)
                return
            for neighbour in adj[node]:
                if neighbour != parent:
                    dfs(neighbour, node, totalPathCost)
        answer = -float("inf")
        dfs(0, -1, 0)
        return answer
