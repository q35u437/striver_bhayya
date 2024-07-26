class Solution:
    def averageWaitingTime(self, customers: List[List[int]]) -> float:
        total_time = 0.0
        waiting_time = []
        for customer in customers:
            if total_time < customer[0]:
                total_time += (customer[0] - total_time)
                waiting_time.append(customer[1])
                total_time += (customer[1])
            else:
                waiting_time.append(total_time - customer[0])
                waiting_time[-1] += (customer[1])
                total_time += (customer[1])
        print(waiting_time)
        return sum(waiting_time) / len(waiting_time)
