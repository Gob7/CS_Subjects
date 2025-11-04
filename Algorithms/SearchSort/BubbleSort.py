def bubbleSort(arr):
    for i in range(1, len(arr)):
        for j in range(len(arr) - i):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]


while True:
    try:
        l = list(eval(input("\nEnter a list of comparable types: ")))
        bubbleSort(l)
        print("The sorted list is", l)
        choice = input('\nEnter "n" to end the programme: ')

        if choice == "n":
            break
    except:
        print("You entered something wrong; SORRY.")
        break

print("\nThank you!!!")
