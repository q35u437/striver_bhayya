def bellman_ford(self, V, edges, S):
    distances = [float("inf") for i in range(V)]
    distances[S] = 0
    
    for i in range(V-1):
        for u, v, w in edges:
            if distances[u] + w < distances[v]:
                distances[v] = distances[u] + w
    
  #checking for negative cycles
    for u, v, w in edges:
        if distances[u] + w < distances[v]:
            return [-1]

    return distances
