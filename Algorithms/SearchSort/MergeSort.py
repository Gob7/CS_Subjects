def mergeSort(arr):
    if len(arr) > 1:
        l1 = arr[: len(arr) // 2]
        l2 = arr[len(arr) // 2 :]
        mergeSort(l1)
        mergeSort(l2)
        i = j = k = 0
        while i < len(l1) and j < len(l2):
            if l1[i] < l2[j]:
                arr[k] = l1[i]
                i += 1
            else:
                arr[k] = l2[j]
                j += 1
            k += 1
        while i < len(l1):
            arr[k] = l1[i]
            i += 1
            k += 1
        while j < len(l2):
            arr[k] = l2[j]
            j += 1
            k += 1


while True:
    try:
        l = list(eval(input("\nEnter a list of comparable types: ")))
        mergeSort(l)
        print("The sorted list is", l)

        choice = input('\nEnter "n" to end the programme: ')
        if choice == "n":
            break
    except:
        print("You entered something wrong; SORRY.")
        break

print("\nThank you!!!")
