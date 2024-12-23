from collections import defaultdict
import heapq
class Solution:
    def leftmostBuildingQueries(self, heights: List[int], queries: List[List[int]]) -> List[int]:
        new_queries =  []
        for query in queries:
            l, r = query
            new_queries.append((min(l, r),max(l, r)))
        data = defaultdict(list)
        answer = [-1 for i in range(len(queries))]
        for i in range(len(queries)):
            l, r = new_queries[i]
            if l == r or heights[r] > heights[l]:
                answer[i] = r
                continue
            data[r].append((max(heights[l], heights[r]), i))
        pq = []
        heapq.heapify(pq)
        for i in range(len(heights)):
            while pq and pq[0][0] < heights[i]:
                node = heapq.heappop(pq)
                answer[node[1]] = i
            if data[i]:
                for dat in data[i]:
                    heapq.heappush(pq, dat)
            
        return answer
