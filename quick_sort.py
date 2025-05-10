import random
import time


def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    pivot = arr[0]
    left = [x for x in arr[1:] if x <= pivot]
    right = [x for x in arr[1:] if x > pivot]
    return quick_sort(left) + [pivot] + quick_sort(right)


array = [random.randint(1, 100) for _ in range(10)]
print(f"Original Array: {array}")


start = time.time()
sorted_array = quick_sort(array)
end = time.time()


print(f"Sorted Array (Quick Sort): {sorted_array}")
print(f"Time Taken: {end - start:.6f} seconds")


print("Time Complexity: O(n log n) - efficient for larger datasets.")
