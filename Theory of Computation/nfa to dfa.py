print('NFA to DFA conversion: \n')
print('States: 0(initial), 1, 2 ...')
print('Inputs: 0, 1, 2 ...')
print('Limitation: can take a maximum of  states and inputs')
print('-1 means dead state')
print('Enter without spaces')
while True:
    print('\nEnter details of NFA')
    state,inp=eval(input('Enter number of states and inputs: '))
    nfa=[]
    print('State Input\tOutput')
    for i in range(state):
        x=[]
        for j in range(inp):
            print(i,'\t',j,':\t',end='')
            x.append(input())
        nfa.append(x)
    fin=input('Final states: ')

    print('\n\n')
    for i in range(-1,state):
        for j in range(-1,inp):
            if i==-1 and j==-1:
                print('NFA',end='\t')
                continue
            if i==-1 or j==-1:
                print(i+j+1,end='\t')
                continue
            print(nfa[i][j],end='\t')
        print()
    print('Final states:',fin)

    dfa=[]
    dfa_s=[]
    f=[]
    sta='0'
    p1=0
    p2=-1
    while True:
        if sta not in dfa_s:
            x=['']*inp
            for i in sta:
                for j in range(inp):
                    l=nfa[int(i)][j]
                    for k in l:
                        if k not in x[j]:
                            x[j]+=k
            dfa_s.append(sta)
            for i in range(inp):
                l=list(x[i])
                l.sort()
                x[i]=''
                x[i]=x[i].join(l)
            dfa.append(x)
            for i in fin:
                if i in sta:
                    f.append(sta)
                    break
        p2+=1
        if p2==inp:
            p2=0
            p1+=1
        sta=dfa[p1][p2]
        if len(dfa)*inp==(p1+1)*(p2+1) and sta in dfa_s:
            break
    print('\n\n')
    for i in range(-1,len(dfa_s)):
        for j in range(-1,inp):
            if i==-1 and j==-1:
                print('DFA',end='\t')
                continue
            if i==-1:
                print(j,end='\t')
                continue
            if j==-1:
                if dfa_s[i]=='': dfa_s[i]='-1'
                print(dfa_s[i],end='\t')
            else:
                if dfa[i][j]=='': dfa[i][j]='-1'
                print(dfa[i][j],end='\t')
        print()
    print('Final states:',f)

