#https://www.hackerrank.com/challenges/bfsshortreach

from queue import Queue

MAX = 1005
V = None
E = None

vis = [False]*MAX
dis = [0]*MAX
graph = [[] for i in range(MAX)]

def Bfs(s):
    for i in range(1, V+1):
        vis[i] = False
        dis[i] = -1
    
    vis[s] = True
    dis[s] = 0
    
    q = Queue()
    q.put(s)
    
    while (q.empty()==False):
        s = q.get()
        for v in graph[s]:
            if (vis[v] == False):
                vis[v] = True
                dis[v] = dis[s] + 1
                q.put(v)

if __name__ == '__main__':
    q = int(input())
    while (q):
        q-=1
        graph = [[] for i in range(MAX)]
        V,E = map(int, input().split())
        for i in range(E):
            u,v = map(int, input().split())
            graph[u].append(v)
            graph[v].append(u)
                
   
        s = int(input())
        Bfs(s)
        for i in range(1,V+1):
            if (i == s):
                continue
            if (dis[i] != -1):
                dis[i]*=6
            print(dis[i], end = ' ')
            
        print("\n", end = "")
    


                
                
                

