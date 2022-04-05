def merge(A, mid, low, high):
    B = []
    i = low
    j = mid+1
    k = low

    while i <= mid and j <= high:
        if A[i] < A[j]:
            B[k] = A[i]
            k += 1
            i += 1
        else:
            B[k] = A[j]
            k += 1
            j += 1

    while i <= mid:
        B[k] = A[i]
        k += 1
        i += 1

    while j <= high:
        B[k] = A[j]
        k += 1
        j += 1
    
    for i in range(len(B)):
        A[i] = B[i]


def merge_sort(A, low, high):
    '''this will continuously divide the array into single elements'''
    while low < high:
        mid = (low+high)//2

        merge_sort(A, low, mid)
        merge_sort(A, mid+1, high)

        merge(A, mid, low, high)


# driver code 
data = [1,2,1,3,2,44,22,43]
print(data)
merge_sort(data, 0, (len(data)-1))
print(data)