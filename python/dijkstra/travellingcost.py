#http://www.spoj.com/problems/TRVCOST/
import queue
 
MAX = 500
INF = int(1e9)
 
# khai báo class Node với id là tên đỉnh, dist là chi phí
# define operator __lt__ (less than) cho class, so sánh theo dist nhỏ hơn, dùng trong PriorityQueue
class Node:
    dist = 0
    id = 0
    def __init__(self, id, dist):
        self.dist = dist
        self.id = id
    def __lt__(self, other):
        return self.dist <= other.dist
 
def Dijkstra(s, graph, dist):
    pq = queue.PriorityQueue()
    pq.put(Node(s, 0))
    dist[s] = 0
    while pq.empty() == False:
        top = pq.get()
        node = top.id
        d = top.dist
        for neighbor in graph[node]:
            if d + neighbor.dist < dist[neighbor.id]:
                dist[neighbor.id] = d + neighbor.dist
                pq.put(Node(neighbor.id, dist[neighbor.id]))
                path[neighbor.id] = node
 
if __name__ == '__main__':
    n = int(input())
    graph = [[] for i in range(MAX+5)]
    dist = [INF for i in range(MAX+5)]
    path = [-1 for i in range(MAX+5)]
    for i in range(n):
        u, v, w = map(int, input().split())
        graph[u].append(Node(v, w))
        graph[v].append(Node(u, w))
 
    s = int(input())
    Dijkstra(s, graph, dist)
 
    q = int(input())
    for i in range(q):
        v = int(input())
        print(dist[v] if dist[v] != INF else "NO PATH")


