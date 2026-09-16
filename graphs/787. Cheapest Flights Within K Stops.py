class Solution:
    def dfs(self, source, destination, adj, distances, limit):
        if limit == 0:
            if source == destination:
                return distances[source][limit]
            else:
                for to, time in adj[source]:
                    if to == destination:
                        distances[source][limit] = time
                        return distances[source][limit]
                distances[source][limit] = float("inf")
                return distances[source][limit]
        if source == destination:
            if limit >= 0:
                return distances[source][limit]
            else:
                return float("inf")
        elif distances[source][limit] != None:
            return distances[source][limit]
        else:
            answer = float("inf")
            for to, time in adj[source]:
                answer = min(answer, time + self.dfs(to, destination, adj, distances, limit - 1))
            distances[source][limit] = answer
            return distances[source][limit]

    def findCheapestPrice(self, n: int, flights: list[list[int]], src: int, dst: int, k: int) -> int:
        adj = [[] for i in range(n)]
        for x, y, time in flights:
            adj[x].append((y, time))
        distances = [
            [
                None for i in range(k+1)
            ]
            for j in range(n)
        ]
        for i in range(k+1):
            distances[dst][i] = 0
        self.dfs(src, dst, adj, distances, k)
        return distances[src][k] if  distances[src][k] != float("inf") else -1
