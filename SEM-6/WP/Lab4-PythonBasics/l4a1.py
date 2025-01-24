# Write a python program to select smallest element from a list in an expected linear time.

arr = [58, 12, 96, 36, 41, 89, 8]
smallest = arr[0]
for i in arr:
    if i < smallest:
        smallest = i

print("Smallest element in the list is %d" % smallest)
