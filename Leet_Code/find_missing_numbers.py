"""
Find All Numbers Disappeared in an Array

Solution
Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.



Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]
Example 2:

Input: nums = [1,1]
Output: [2]
"""


def find_missing(nums):
    # Iterate over each of the elements in the original array
    for i in range(len(nums)):
        # Treat the value as the new index
        new_index = abs(nums[i]) - 1

        # Check the magnitude of value at this new index
        # If the magnitude is positive, make it negative
        # thus indicating that the number nums[i] has
        # appeared or has been visited.
        if nums[new_index] > 0:
            nums[new_index] *= -1  # make value negative

    # Response array that would contain the missing numbers
    result = []

    # Iterate over the numbers from 1 to N and add all those
    # that have positive magnitude in the array
    for i in range(1, len(nums) + 1):
        if nums[i - 1] > 0:
            result.append(i)
    return result


nums = [4, 3, 2, 7, 8, 2, 3, 1]

print(f"Missing elements are {find_missing(nums)}")
