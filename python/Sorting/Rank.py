#http://www.codeforces.com/problemset/problem/551/A
n = int(input())
a=list(map(int, input().split()))
b=a[:]
a.sort(key = lambda x : -x)
rank=[0]*10000
rank[a[0]] = 1
cur_rank = 1
cnt = 1
for i in range(1,n):
    if (a[i] != a[i-1]):
        cur_rank+=cnt
        cnt = 0
    cnt+=1
    rank[a[i]] = cur_rank

for i in range (n):
    print(rank[b[i]], end=" ")




