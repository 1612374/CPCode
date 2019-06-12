#http://codeforces.com/problemset/problem/572/A
def inp():
    return map(int, input().split())

na,nb=inp()
k,m=inp()
a=list(inp())
b=list(inp())

if (a[k-1] < b[nb - m]):
    print("YES")
else:
    print("NO")
