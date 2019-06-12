#http://codeforces.com/contest/1006/problem/E

MAX =  2 * 100000+1

graph = [[] for i in range(MAX)]
vis = [False] * MAX
res = [] 
tin = [0 for i in range(MAX)]
tout = [0 for i in range(MAX)]

def dfs(u):
    vis[u] = True
    res.append(u)
    tin[u] = len(res)

    for v in graph[u]:
        if vis[v] == False:
            dfs(v)
            
    tout[u] = len(res)
                

n,q = map(int, input().split(' '))

a = list(map(int, input().split(' ')))

for i in range(len(a)):
    graph[a[i]].append(i+2)


dfs(1)

for i in range(q):
    a, b = map(int, input().split(' '))

    if b > tout[a] - tin[a] + 1:
        print(-1)
    else:
        print(res[tin[a]+b-2])



