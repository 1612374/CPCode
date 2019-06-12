#http://codeforces.com/problemset/problem/387/B
def inp():
    return map(int, input().split())

n,m=inp()
a=list(inp())
b=list(inp())

i,j=0,0
while ((i < n) & (j < m)):
    if (b[j] >= a[i]):
        i+=1
    j+=1

print(n-i)