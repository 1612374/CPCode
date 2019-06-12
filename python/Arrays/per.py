n=int(input())
a=list(map(int,input().split()))

imax=0
imin=0
vmax=0
vmin=100001

for i in range(n):
    if (vmax < a[i]):
        vmax=a[i]
        imax=i
    if (vmin > a[i]):
        vmin=a[i]
        imin=i

mi = min(imax, imin)
ma = max(imax, imin)


res = max(n-1-mi, ma)

print(res) 
