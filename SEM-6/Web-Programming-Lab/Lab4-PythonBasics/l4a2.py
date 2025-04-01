# Write a python program to implement bubble sort.

def bubble_sort(arr):  
    n = len(arr)  
    
    for i in range(n):   
        for j in range(0, n-i-1):  
            if arr[j] > arr[j+1]:  
                arr[j], arr[j+1] = arr[j+1], arr[j]  
    
if __name__ == "__main__":   
    sample_list = [64, 34, 25, 12, 22, 11, 90]  
    print("Original List:", sample_list)  
    bubble_sort(sample_list)  
    print("Sorted List:", sample_list)  