class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        left = 0
        right = len(nums) - 1
        while left <= right:
            middle = (left + right) // 2
            if nums[middle] == target:
                return True

            #if middle is not equal to any of left of right you can tell which part is sorted easily or else you can't so you search for unique elements to compare
            if not (nums[left] != nums[middle] or nums[middle] != nums[right]):
                right -= 1
                left += 1
                continue

            if nums[left] <= nums[middle]:
                if nums[left] <= target < nums[middle]:
                    right = middle - 1
                else:
                    left = middle + 1
            else:
                if nums[middle] < target <= nums[right]:
                    left = middle + 1
                else:
                    right = middle - 1
        return False
