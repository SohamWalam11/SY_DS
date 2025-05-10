import random
import time

def selection_sort(arr):
    n = len(arr)
    for i in range(n):
        min_index = i
        for j in range(i+1, n):
            if arr[j] < arr[min_index]:
                min_index = j
        arr[i], arr[min_index] = arr[min_index], arr[i]


array = [random.randint(1, 100) for _ in range(10)]
print(f"Original Array: {array}")


start = time.time()
selection_sort(array)
end = time.time()


print(f"Sorted Array (Selection Sort): {array}")
print(f"Time Taken: {end - start:.6f} seconds")


print("Time Complexity: O(n²) - suitable for small datasets.")
