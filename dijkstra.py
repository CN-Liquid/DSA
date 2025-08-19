import math
from queue import PriorityQueue
graph = { 
    's':{'t':10 , 'y':5},
    't':{'x':1 , 'y':2},
    'x':{'z':4},
    'y':{'x':9,'z':2 , 't':3},
    'z':{'x':6,'s':7}
}

def initSingleSource(graph , source):
    cost = dict()
    prev = dict()
    for vertex in graph.keys():
        cost[vertex] = math.inf
        prev[vertex] = ' '
    cost[source] = 0
    return cost,prev

def relax(graph , source , dest , cost , prev):
    if(cost[dest] > (cost[source] + graph[source][dest])):
        cost[dest] = cost[source] + graph[source][dest]
        prev[dest] = source
    return cost,prev

def dj(graph,source):
    cost,prev = initSingleSource(graph,source)
    PQ = PriorityQueue()

    for vertex in graph.keys():
        PQ.put((cost[vertex] , vertex))
    visited = []

    while(len(visited) != len(graph.keys())):
        _ , currentVertex = PQ.get()
        visited.append(currentVertex)

        for nb in graph[currentVertex]:
            if nb not in visited:
                cost,prev = relax(graph , currentVertex , nb , cost , prev)
                PQ.put((cost[nb],nb))
    return cost,prev


def recPath(dest , prev ):
    path = dest
    while prev[dest]!=' ':
        path  = prev[dest]+'->'+path
        dest = prev[dest]
    return path

cost , prev  = dj(graph,'t')

print(cost)
print(prev)

for vertex in graph.keys():
    print(f'Shortest path from t to {vertex}  is {recPath(vertex,prev)}')
    print(f'Cost is {cost[vertex]}')


