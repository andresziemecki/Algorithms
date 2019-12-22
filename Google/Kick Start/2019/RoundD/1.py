def xor(L):
    tmp = L[0]
    for i in range(1,len(L)):
        tmp = tmp^L[i]
    return tmp

def foo(Lista):
    if (len(Lista) == 1):
        if (len(bin(Lista[0]).split('1'))%2):
            return 1
        else:
            return 0
    x = 0
    for i in range(len(Lista) - 1):
        for j in range(i+1):
            x = xor(Lista[j:len(Lista)-i+j])
            if (len(bin(x).split('1'))%2 ):
                #print(Lista[j:len(Lista)-i+j])
                return (len(Lista) - i)
    return 0;

T = int(input());
for t in range(1,T+1):
    N, Q = [int(f) for f in input().split(' ')]
    Lista = [int(f) for f in input().split(' ')]
    result = list()
    for q in range(Q):
        Pi, Vi = [int(f) for f in input().split(' ')]
        Lista[Pi] = Vi
        result.append(foo(Lista))
    print("Case #{}: ".format(t), flush=True, end='')
    for r in range(len(result)-1):
        print(str(result[r]) + " ", flush=True, end='')
    print(str(result[len(result)-1]))
