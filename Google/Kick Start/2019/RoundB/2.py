def totalE (Lista):
    E_i = 0
    E_f = 0
    for j in range(len(Lista)):
        if j==0:
            E_i = E_i + Lista[j][1]
            E_f = E_i - Lista[j][0]*Lista[j][2]
            Lista[j][3]
        else:
            E_i = E_i + Lista[j][1]
            E_f = E_i - Lista[j][0]*Lista[j][2] - resta(Lista, j, Lista[0])
        if ( E_f < 0:
            return E_i
    return E_i

def resta(Lista, n, S):
    suma = 0
    for i in range(n-1):
        if (Lista[n][3] != 0):
            if (Lista[n][3] - Lista[n][1]/Lista[n][2]*S > 0):
                sum = sum + Lista[n][1]/Lista[n][2]*S
                Lista[n][3] = Lista[n][3] - Lista[n][1]/Lista[n][2]
            else:
                sum = sum + Lista[n][3]
                Lista[n][3] = 0
    return sum



T = int(input());
for t in range(1,T+1):
    N = int(input());
    Lista = [[0]]*N
    for n in range(0,N):
        #import pdb; pdb.set_trace()
        Lista[n] = [int(f) for f in input().split(' ')];
        Lista[n].append(0.)
    print(Lista)
    for f in range(len(Lista)):
        Lista[f][3] = float(Lista[f][0]) - float(Lista[f][1]/Lista[f][2])
    Lista.sort(key=lambda x: x[3], reverse=True)
    Etot = totalE(Lista)
    print("Case #{}: {}".format(t, Etot), flush=True)
