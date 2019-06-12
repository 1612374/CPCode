#http://codeforces.com/problemset/problem/557/B
n,w = map(int,input().split())
a = list(map(int, input().split()))
a.sort()
x = a[0]
y = a[n]

mini = min(float(y/2), float(x))
res = float(mini*3*n)
if (res < w): print("%.6f" % res)
else : print(w)
