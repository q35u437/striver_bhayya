def first_index(nums, target, low, high, index):
    if low <= high:
        middle = (low + high) // 2
        
        if nums[middle] < target:
            return first_index(nums, target, middle+1, high, index)
        elif nums[middle] > target:
            return first_index(nums, target, low, middle-1, index)
        else:
            return first_index(nums, target, low, middle-1, middle)
    return index
