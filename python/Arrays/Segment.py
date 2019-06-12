#http://codeforces.com/problemset/problem/242/B

def inp():
    return map(int, input().split())

n=int(input())
l=list()
l.extend(100000*[0])
r=list()
r.extend(100000*[0])

idxl=0
idxr=0
minl=1000000001
maxr=0

for i in range(n):
    l[i], r[i] = inp()
    if (l[i] < minl):
        minl=l[i]
        idxl=i
    if (r[i] > maxr):
        maxr = r[i]
        idxr = i


for i in range(n):
    if ((l[i] == minl) &( r[i] == maxr)):
        print(i+1)
        exit()
        
print(-1)
    
