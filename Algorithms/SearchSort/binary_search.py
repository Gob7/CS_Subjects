def bsearch (array, item, index=0):
        half=len(array)//2
        if array[half]==item:
                return index+half
        elif array[half]>item:
                return bsearch (array[:half], item, index)
        elif array[half]<item:
                return bsearch (array[half+1:], item, index+half+1)
while True:
        try:
                print('\nEnter a list of same datatype items which can be compared/sorted')
                print('e.g. real numbers, strings, lists, tuples:')
                array=list(eval(input()))
                array.sort()
                print('\nSorted list is:\n\t',array)
                while True:
                        try:
                                item=eval(input('\nEnter item: '))
                                if item in array:
                                        print(item,'found at index',bsearch(array, item))
                                else:
                                        print(item,'is absent in the given array.')
                        except:
                                print('Invalid item entered.')
                        choice=input('\nPress "e" or "E" to exit/experiment on other lists: ')
                        if choice in ('e','E'):
                                break
        except:
                print('Invalid list entered.')
        choice=input('\nPress "e" or "E" to exit: ')
        if choice in ('e','E'):
                break
print('\n\tThank You!!!')
