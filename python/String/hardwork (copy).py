def norm(s):
    r = s.replace(';','')
    r = r.replace('-','')
    r = r.replace('_','')
    r = r.lower()
    return r
 
s1 = norm(input())
s2 = norm(input())
s3 = norm(input())
n = int(input())
cat = [s1+s2+s3,s1+s3+s2,s2+s1+s3,s2+s3+s1,s3+s1+s2,s3+s2+s1]
 
for i in range(n):
    s = norm(input())
    if s in cat:
        print("ACC")
    else:
        print("WA")
