#quick sorting (key=last index)
def quick(arr,low=0,high=-1):
    if high==-1: high+=len(arr)
    i=low-1
    for j in range(low,high):
        if arr[j]<arr[high]:
            i+=1
            arr[j],arr[i]=arr[i],arr[j]
    i+=1
    arr[i],arr[high]=arr[high],arr[i]
    if i!=low: quick(arr,low,i-1)
    if i!=high: quick(arr,i+1,high)
while True:
    try:
        l=list(eval(input('\nEnter a list of comparable types: ')))
        quick(l)
        print('The sorted list is',l)
        choice=input('\nEnter "n" to end the programme: ')
        if choice=='n':
            break
    except:
        print('You entered something wrong; SORRY.')
        break
print('\nThank you!!!')