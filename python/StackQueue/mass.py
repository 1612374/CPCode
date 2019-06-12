#http://www.spoj.com/problems/MMASS 
import queue


def inp():
    return map(int, input().split(' '))


atom = input()
stack = queue.LifoQueue()
sum = 0
i = 0
while (i < len(atom)):
    #   Nếu gặp dấu đóng ngoặc thì bắt đầu tính khối lượng
    if (atom[i] == ')'):
        i += 1
        number = 1
        sum_local = 0
        #       Nếu phía sau dấu ngoặc đó là một con số (CO2H)3 thì phải tính tổng trong ngoặc rồi nhân cho 3.
        if (atom[i].isnumeric()):
            number = atom[i] - '0'
        else:
            #           Nếu phía sau dấu ngoặc không phải là một con số mà là dấu mở ngoặc tiếp theo thì ko tăng i TH này (OH2H)(C(H)
            i -= 1
        while (True):
            temp = stack.get()
            if (temp == -1):
                break
            sum_local += temp
        #       Nhân với số phí sau dấu ngoặc ')'
        sum_local = sum_local * number
        stack.put(sum_local)
    else:
        #       Push các giá trị vào trong stack
        #       Trường hợp gặp số ở phía sau CO2H thì lưu 12 rồi lưu 32 (16*2)...
        if (atom[i].isnumeric()):
            number = stack.get() * (atom[i] - '0')
            stack.put(number)
        if (atom[i] == '('):
            stack.put(-1)
        if (atom[i] == 'H'):
            stack.put(1)
        if (atom[i] == 'O'):
            stack.put(16)
        if (atom[i] == 'C'):
            stack.put(12)
    i += 1
while (stack.empty == False):
    sum += stack.get()
print(sum)