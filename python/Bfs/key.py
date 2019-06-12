#https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/dhoom-4/description/

from queue import Queue

x,y = map(int, input().split())
n = int(input())
a = list(map(int, input().split()))

def bfs(s, e):
    dis = [-1] * 100001
    dis[s] = 0
    vis = [False] * 100001
    q = Queue()
    
    q.put(s)
    
    while (q.empty() == False):
        tmp = q.get()
        if (tmp == e):
            return dis[e]
        
        for i in range(n):
            k = tmp*a[i]
            k %= 100000
            if (vis[k] == False):
                vis[k] = True
                dis[k] = dis[tmp] + 1
                q.put(k)
                
    return -1
                
if __name__ == '__main__':
    print(bfs(x, y))
                
