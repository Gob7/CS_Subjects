def bottomUpMerge(arr, low, mid, high):
    n = high - low + 1
    i, j, k = 0, low, mid + 1
    temp = [0] * n
    while j <= mid and k <= high:
        if arr[j] < arr[k]:
            temp[i] = arr[j]
            j += 1
        else:
            temp[i] = arr[k]
            k += 1
        i += 1
    while j <= mid:
        temp[i] = arr[j]
        j += 1
        i += 1
    while k <= high:
        temp[i] = arr[k]
        k += 1
        i += 1
    for i in range(n):
        arr[low + i] = temp[i]


def bottomUpMergeSort(arr):
    item = 1
    while item <= len(arr):
        low = 0
        while low < len(arr):
            mid = low + item - 1
            mid = mid if mid < len(arr) else len(arr) - 1
            high = low + 2 * item - 1
            high = high if high < len(arr) else len(arr) - 1
            bottomUpMerge(arr, low, mid, high)
            low += 2 * item
        item *= 2


while True:
    try:
        l = list(eval(input("\nEnter a list of comparable types: ")))
        bottomUpMergeSort(l)
        print("The sorted list is", l)
        choice = input('\nEnter "n" to end the programme: ')

        if choice == "n":
            break
    except:
        print("You entered something wrong; SORRY.")
        break

print("\nThank you!!!")
