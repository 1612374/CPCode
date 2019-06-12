#http://codeforces.com/problemset/problem/161/A
def inp():
    return map(int, input().split())

n,m,x,y = inp()
a=list(inp())
b=list(inp())

res = list()

i,j = 0,0
while ((i < n) & (j < m)):
    if (b[j] < a[i] - x):
        j+=1
    elif (b[j] > a[i] + y):
        i+=1
    else:
        res.append([i+1,j+1])
        i+=1
        j+=1


print(len(res))
for x in range(len(res)):
    print(res[x][0], res[x][1])