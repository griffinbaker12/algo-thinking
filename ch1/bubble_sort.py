def bubble_sort(arr):
    for _ in range(len(arr)):
        for j in range(len(arr) - 1):
            if arr[j] > arr[j + 1]:
                arr[j + 1], arr[j] = arr[j], arr[j + 1]


if __name__ == "__main__":
    a = [64, 34, 25, 12, 22, 11, 90]
    bubble_sort(a)
