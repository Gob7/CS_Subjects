# Fibonacci series (Indian Series)
while True:
    try:
        w = input(
            '\nPress\t>> "0" for Fibonacci series starting from 0,\n\t>> "1" for Fibonacci series starting from 1,\n\t>> <any key*> for Fibonacci series starting from your choice: '
        )
        c = int(eval(input("\nEnter total number of terms: ")))
        print()
        if c == 0:
            print("Fibonacci series for the given inputs is the following:\n")
        elif w == "0":
            if c == 1:
                print("Fibonacci series for the given inputs is the following:\n")
                print("\t", 0)
            elif c == 2:
                print("Fibonacci series for the given inputs is the following:\n")
                print("\t", 0, "\n\t", 1, sep="")
            else:
                a = 0
                b = 1
                print("Fibonacci series for the given inputs is the following:\n")
                print("\t", 0, "\n\t", 1, sep="")
                for i in range(0, c - 2):
                    f = a + b
                    a = b
                    b = f
                    print("\t", f, sep="")
        elif w == "1":
            if c == 1:
                print("Fibonacci series for the given inputs is the following:\n")
                print("\t", 1)
            elif c == 2:
                print("Fibonacci series for the given inputs is the following:\n")
                print("\t", 1, "\n\t", 1, sep="")
            else:
                a = 1
                b = 1
                print("Fibonacci series for the given inputs is the following:\n")
                print("\t", 1, "\n\t", 1, sep="")
                for i in range(0, c - 2):
                    f = a + b
                    a = b
                    b = f
                    print("\t", f, sep="")
        else:
            a = complex(eval(input("Enter the first number: ")))
            b = complex(eval(input("Enter the second number: ")))
            print()
            if c == 1:
                print("Fibonacci series for the given inputs is the following:\n")
                print("\t", a)
            elif c == 2:
                print("Fibonacci series for the given inputs is the following:\n")
                print("\t", a, "\n\t", b, sep="")
            else:
                print("Fibonacci series for the given inputs is the following:\n")
                print("\t", a, "\n\t", b, sep="")
                for i in range(0, c - 2):
                    f = a + b
                    a = b
                    b = f
                    print("\t", f, sep="")
    except:
        print("You entered something wrong; SORRY.")
    choice = input('\nEnter "n" to end the programme: ')
    if choice == "n":
        break
print("\nThank You!!!")
