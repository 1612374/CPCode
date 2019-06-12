#http://codeforces.com/problemset/problem/677/A
n,h = map(int, input().split(' '))
arr=list(map(int, input().split()))

res = 0

for i in range(n):
    if (arr[i] > h):
        res+=2
    else:
        res+=1
        
print(res)
