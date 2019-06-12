# get n
n = input()
lis_segment = []
 
# create a list named lis_segment which contain a list which is the splited elements of each line input
for i in range(n):
    lis_segment.append(map(int, raw_input().split()))
 
# find the min of all element on the left, zero index
l = min(x[0] for x in lis_segment)
 
# find max of all element on the right, 1 index
r = max(y[1] for y in lis_segment)
 
# check if any segment in lis_segment is equal to [l, r]
# print the position of found result which is index + 1
if [l, r] in lis_segment:
    print lis_segment.index([l, r]) + 1  
else:
    print -1

