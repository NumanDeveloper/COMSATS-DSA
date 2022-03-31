'''
* Logic:
* select a key value and assume it pre-sorted
* take j=i-1
* compare key with its left side elements and shift A[j] to A[j+1] until j>=0
* set A[j+1] = key
'''

def insertion_sort(array):
    # outer loop for passes
    for i in range(len(array)):
        key = array[i]
        j = i-1
        while(j>=0 and array[j] > key):
            array[j+1] = array[j] # shifting to right
            j-=1
        
        array[j+1] = key
    print(f"Sorted Array:\n{array}")


# driver code
array = [2,3,5,1,8,10]
print(array)
insertion_sort(array)