import math
graph = { 
    's':{'t':10 , 'y':5},
    't':{'x':1 , 'y':2},
    'x':{'z':4},
    'y':{'x':9,'z':2 , 't':3},
    'z':{'x':6,'s':7}
}

graphAdjecancy  = [
    [0,10,math.inf ,5,math.inf ],
    [math.inf,0,1,2,math.inf],
    [math.inf , math.inf , 0 , math.inf , 4],
    [math.inf , 3 , 9,0,2],
    [7,math.inf , 6 ,math.inf , 0 ]
]

def floydWarshall(adj):
    n = len(adj)

    D = dict()
    D[0] = adj

    for k in range(n):
        D[k+1] = D[k]
        for i in range(n):
            for j in range(n):
                D[k+1][i][j] = min(D[k][i][j],D[k][i][k]+D[k][k][j])
    
    return D

D=floydWarshall(graphAdjecancy)

print(D[len(graphAdjecancy)])