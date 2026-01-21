# Fibonacci series (Indian Series)
print("Fibonacci series (Indian Series)")
print("--------------------------------\n")
fibonacciArray = [0, 1]


def fibonacciBottomUp(arr, term=2, printRequired=0):
    if term < 1:
        return

    arrLength = len(arr)
    if term > arrLength:
        for i in range(arrLength, term):
            arr.append(arr[i - 2] + arr[i - 1])

    if printRequired:
        print("Series goes like...")
        for i in range(term):
            print("\t\t", arr[i])

    return arr[term - 1]


def main():
    try:
        custom = input("\nPress '0' for custom start\t: ")
        term = int(eval(input("Enter total number of terms\t: ")))
        print()

        if custom == "0":
            n1 = complex(eval(input("First number\t: ")))
            n2 = complex(eval(input("Second number\t: ")))
            arr = [n1, n2]
            ans = fibonacciBottomUp(arr, term, 1)
        else:
            ans = fibonacciBottomUp(fibonacciArray, term, 1)

        print("\n(", term, " th) term is ", ans, sep="")
    except:
        print("Wrong input given, try again!")


while True:
    main()
    repeat = input("\n\nPress '1' to repeat: ")
    if repeat != "1":
        break
