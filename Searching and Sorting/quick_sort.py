# Quick sort in Python

# function to find the partition position
def partition(array, low, high):
  # choose the rightmost element as pivot
  pivot = array[high]

  # pointer for storing smaller elememts on left side
  left = low - 1

  # traverse through all elements
  # compare each element with pivot
  for j in range(low, high):
    if array[j] <= pivot:
      # if element smaller than pivot is found
      # swap it with the left element pointed by left
      left = left + 1 # increment left bcz we initialized it to -1
      # swapping element at left with element at j
      (array[left], array[j]) = (array[j], array[left])

  # swap the pivot element with the left element specified by left
  (array[left + 1], array[high]) = (array[high], array[left + 1])

  # return the position from where partition is done
  return left + 1

# function to perform quicksort
def quickSort(array, low, high):
  if low < high:
    # find pivot element such that
    # element smaller than pivot are on the left
    # element greater than pivot are on the right
    pi = partition(array, low, high) # pi reps partition index

    # recursive call on the left of pivot
    quickSort(array, low, pi - 1)

    # recursive call on the right of pivot
    quickSort(array, pi + 1, high)


data = [8, 7, 2, 1, 0, 9, 6]
print("Unsorted Array")
print(data)

size = len(data)

quickSort(data, 0, size - 1)

print('Sorted Array in Ascending Order:')
print(data)