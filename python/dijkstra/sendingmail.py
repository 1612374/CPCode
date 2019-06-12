#https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1927
import queue
class node_in_graph:
    vertice = 0
    distance = 0
    def __init__(self, weight, vertice):
        self.vertice = vertice
        self.distance = weight
 
    def __lt__(a, b):
        return a.distance < b.distance
 
 
def dijkstra(graph, src, des):
    pq = queue.PriorityQueue()
    n = len(graph)
    distance = [10**9 + 10] * n
    distance[src] = 0
    pq.put(node_in_graph(0, src))
    while not pq.empty():
        u = pq.get()
        if u.vertice == des:
            return u.distance
        for v in graph[u.vertice]:
            if distance[v.vertice] > u.distance + v.distance:
                distance[v.vertice] = u.distance + v.distance
                pq.put(node_in_graph(distance[v.vertice], v.vertice))
    return "unreachable"
 
def inp():
    return map(int, input().split(' '))
 
def solve():
    tcase = int(input())
    for test in range(tcase):
        n, m, s, t = inp()
        graph = [[] for i in range(n)]
        for i in range(m):
            u, v, val = inp()
            graph[u].append(node_in_graph(val, v))
            graph[v].append(node_in_graph(val, u))
        print(dijkstra(graph, s, t))
 
solve()
