#http://codeforces.com/problemset/problem/691/A
n=int(input())
arr=list(map(int, input().split()))
cnt = 0

if (n==1):
    if (arr[0] == 1):
        print("YES")
    if (arr[0] == 0):
        print("NO")
    exit()
    

for i in range(n):
    if (arr[i] == 0):
        cnt+=1
    else:
        continue
    
if (cnt == 1):
    print("YES")
else:
    print("NO")
    
    
