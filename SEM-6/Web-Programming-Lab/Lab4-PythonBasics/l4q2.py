# Write a python program to implement binary search with recursion

def binary_search(arr, x):
    low = 0
    high = len(arr) - 1

    while low <= high:
        mid = (low + high) // 2
        if arr[mid] < x:
            low = mid + 1
        elif arr[mid] > x:
            high = mid - 1
        else:
            return mid
    return -1

arr = [5, 6, 89, 152, 600]
x = 89

result = binary_search(arr, x)

if result == -1:
    print("Element is not present in the array")
else:
    print("Element is present at index ", result)