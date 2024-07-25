def last_index(nums, target, low, high, index):
    if low <= high:
        middle = (low + high) // 2
    
        if nums[middle] < target:
            return last_index(nums, target, middle+1, high, index)
        elif nums[middle] > target:
            return last_index(nums, target, low, middle-1, index)
        else:
            return last_index(nums, target, middle+1, high, middle)
    return index
