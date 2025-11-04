def selectionSort(arr):
    for i in range(len(arr)):
        key = i
        for j in range(i + 1, len(arr)):
            if arr[key] > arr[j]:
                key = j
        arr[i], arr[key] = arr[key], arr[i]


while True:
    try:
        l = list(eval(input("\nEnter a list of comparable types: ")))
        selectionSort(l)
        print("The sorted list is", l)

        choice = input('\nEnter "n" to end the programme: ')
        if choice == "n":
            break
    except:
        print("You entered something wrong; SORRY.")
        break

print("\nThank you!!!")
