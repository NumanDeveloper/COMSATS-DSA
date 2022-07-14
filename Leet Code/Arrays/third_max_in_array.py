def third_max(nums):
    # remove duplicates and return list 
    nums = list(set(nums))
    # if length is below 3, return max
    if len(nums) < 3:
        return max(nums)
    # else remove first and second max and return the third max 
    else:
        nums.remove(max(nums))
        nums.remove(max(nums))
        return max(nums)


nums = [1,3,5]
print(f"Third max is {third_max(nums)}")