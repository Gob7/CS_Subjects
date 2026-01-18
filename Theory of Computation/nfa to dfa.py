def printMessage():
    print("\nConverting NFA to DFA")
    print("------------------------\n")
    print("States\t\t:\t0(initial), 1, 2...")
    print("Inputs\t\t:\t0, 1, 2...")
    print("Limitation\t:\tMax 10 states.")
    print("Note\t\t:\t-1 is dead state.")
    print("Suggestion\t:\tEnter without spaces.")


def takeInput():
    print("\nNFA DETAILS")
    stateSymbolsNFA, inputSymbols = eval(input("Enter #states & #inputs: "))

    # transition table indexed as nfa[state][input]
    transitionsNFA = []

    print("\nEnter transitions\nState\t\tInput\t\tOutput")
    print("-----------------------------------------------")
    for i in range(stateSymbolsNFA):

        tempTransition = []
        for j in range(inputSymbols):

            print(i, "\t->\t", j, "\t:\t", end="")
            s = input()
            tempTransition.append("".join(sorted(set(s))))

        transitionsNFA.append(tempTransition)

    finalStatesNFA = input("\nFinal states: ")
    return stateSymbolsNFA, inputSymbols, transitionsNFA, finalStatesNFA


def printNFA(stateSymbolsNFA, inputSymbols, transitionsNFA, finalStatesNFA):

    for i in range(-1, stateSymbolsNFA):
        for j in range(-1, inputSymbols):

            if i == -1 and j == -1:
                print("NFA", end="\t")
            elif i == -1 or j == -1:
                print(i + j + 1, end="\t")
            else:
                print(transitionsNFA[i][j], end="\t")

        print()
    print("\nFinal states:", finalStatesNFA)


def printDFA(stateSymbolsDFA, inputSymbols, transitionsDFA, finalStatesDFA):

    for i in range(len(stateSymbolsDFA)):
        if stateSymbolsDFA[i] == "":
            stateSymbolsDFA[i] = "-1"
        for j in range(inputSymbols):
            if transitionsDFA[i][j] == "":
                transitionsDFA[i][j] = "-1"

    for i in range(-1, len(stateSymbolsDFA)):
        for j in range(-1, inputSymbols):

            if i == -1 and j == -1:
                print("DFA", end="\t")
            elif i == -1:
                print(j, end="\t")
            elif j == -1:
                print(stateSymbolsDFA[i], end="\t")
            else:
                print(transitionsDFA[i][j], end="\t")

        print()
    print("\nFinal states:", finalStatesDFA)


def convertNFAtoDFA(inputSymbols, transitionsNFA, finalStatesNFA):
    stateSymbolsDFA = []
    finalStatesDFA = []
    currentState = "0"
    # transition table indexed as dfa[state][input]
    transitionsDFA = []

    stateIndex = 0
    inputIndex = -1
    while True:
        if currentState not in stateSymbolsDFA:

            stateSymbolsDFA.append(currentState)
            tempTransition = [""] * inputSymbols

            for i in currentState:
                for j in range(inputSymbols):
                    tempTransition[j] += transitionsNFA[int(i)][j]
                    tempTransition[j] = "".join(sorted(set(tempTransition[j])))

            transitionsDFA.append(tempTransition)
            for i in finalStatesNFA:
                if i in currentState:
                    finalStatesDFA.append(currentState)
                    break

        inputIndex += 1
        if inputIndex == inputSymbols:
            inputIndex = 0
            stateIndex += 1
        currentState = transitionsDFA[stateIndex][inputIndex]

        if currentState in stateSymbolsDFA and (
            len(transitionsDFA) * inputSymbols == (stateIndex + 1) * (inputIndex + 1)
        ):
            return stateSymbolsDFA, transitionsDFA, finalStatesDFA


def main():
    printMessage()
    stateSymbolsNFA, inputSymbols, transitionsNFA, finalStatesNFA = takeInput()

    print("\n")
    printNFA(stateSymbolsNFA, inputSymbols, transitionsNFA, finalStatesNFA)

    stateSymbolsDFA, transitionsDFA, finalStatesDFA = convertNFAtoDFA(
        inputSymbols, transitionsNFA, finalStatesNFA
    )

    print("\n")
    printDFA(stateSymbolsDFA, inputSymbols, transitionsDFA, finalStatesDFA)


main()
