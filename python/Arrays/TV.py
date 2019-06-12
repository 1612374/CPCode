#http://codeforces.com/problemset/problem/673/A
n=int(input())
arr=list(map(int, input().split()))



arr.append(90)
    
arr.insert(0, 0)

def truncate(x):
    if (x > 90):
        return 90
    if (x == 0):
        return 90
    return x

res =0

for i in range(n+1):  
    if (arr[i+1] - arr[i] > 15):
        res = arr[i] + 15
        break
        
    
print(truncate(res))
