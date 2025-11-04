# Max Heap
def heapify(arr, start, end, index):
    large = index
    left = (index - start) * 2 + 1 + start
    right = left + 1

    if arr[large] < arr[left] and left < end:
        large = left
    if arr[large] < arr[right] and right < end:
        large = right

    if large != index:
        arr[large], arr[index] = arr[index], arr[large]
        heapify(arr, start, end, large)


def heapSort(arr):
    x = len(arr) / 2 - 1
    # Build Heap
    for i in range(x, -1, -1):
        heapify(arr, 0, len(arr), i)
    # Heap Sort
    for i in range(len(arr) - 1, -1, -1):
        arr[0], arr[i] = arr[i], arr[0]
        heapify(arr, 0, i, 0)


while True:
    try:
        l = list(eval(input("\nEnter a list of comparable types: ")))
        heapSort(l)
        print("The sorted list is", l)
        choice = input('\nEnter "n" to end the programme: ')

        if choice == "n":
            break
    except:
        print("You entered something wrong; SORRY.")
        break

print("\nThank you!!!")
