#https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/bishu-and-his-girlfriend/

MAX = 1002
vis = [False] * MAX
dis = [-1] * MAX
n = 0
graph = [[] for i in range(MAX)]

def inp():
    return map(int, input().split())

def dfs(s):
    vis[s] = True

    for v in graph[s]:
        if (vis[v] == False):
            vis[v] = True
            dis[v] = dis[u] + 1

if __name__ == '__main__':
    n = int(input())
    for i in range (n - 1):
        u,v = inp()
        graph[u].append(v)
        graph[v].append(u)

    q = int(input())
    qarr = []
    for i in range(q):
        qarr.append(int(input()))

    dis[1] = 0

    dfs(1)
    qarr.sort()
    res = 0
    maxx = 0
    for i in range(len(qarr)):
        if (dis[qarr[i]] > maxx):
            maxx = dis[qarr[i]]
            res = i

    print(qarr[res], end='')

