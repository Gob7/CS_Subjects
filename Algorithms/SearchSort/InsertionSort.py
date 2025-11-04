def insertionSort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while key < arr[j] and j > -1:
            arr[j + 1] = arr[j]
            j -= 1
        j += 1
        arr[j] = key


while True:
    try:
        l = list(eval(input("\nEnter a list of comparable types: ")))
        insertionSort(l)
        print("The sorted list is", l)

        choice = input('\nEnter "n" to end the programme: ')
        if choice == "n":
            break
    except:
        print("You entered something wrong; SORRY.")
        break

print("\nThank you!!!")
