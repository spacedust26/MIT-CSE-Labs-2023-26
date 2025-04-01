def twoSum(arr, target):
    n = len(arr)
    for i in range(n):
        for j in range(i + 1, n):
            if arr[i] + arr[j] == target:
                return i, j
    return None 

if __name__ == "__main__":
    arr = [10, 20, 10, 40, 50, 60, 70]
    target = 50

    result = twoSum(arr, target)
    if result:
        print(f"Indices: {result}")
    else:
        print("No solution found")
