# http://www.cnblogs.com/reddest/p/9803268.html
# refer from ↑

# optimize the IsPrime !!!!!!!!!!!!!!!!!
n = 100000001
Del = [0] * (n + 1)
prime = []
# for a in range(2,n + 1):
#     if Del[a] == 0:
#         prime.append(a)
#     for b in prime:
#         if a * b > n: break
#         Del[a * b] = 1
#         if a % b == 0: break

def IsPrime(num, flag):
    if flag == 0:
        for i in range(2, num):
            if num%i == 0:
                return False
        return True
    elif flag == 1: #埃式筛
        is_prime = [True]*(num+1)
        is_prime[0] = is_prime[1] = False # 0 and 1 is not prime
        for i in range(2, num+1):
            if is_prime[i]:
                for j in range(i*i, num+1, i):
                    is_prime[j] = False
        return is_prime[num]
    elif flag == 2: #欧拉筛
        is_prime = [True]*(num+1)
        prime_num = []
        for i in range(2, num+1):
            if is_prime[i]:
                prime_num.append(i)
            for j in range(len(prime_num)):
                if i*prime_num[j] > num:
                    break
                is_prime[i*prime_num[j]] = False
                if i%prime_num[j] == 0:
                    break
        return is_prime[num]
a = 0
while True:
    try:
        a = int(input())
        print(IsPrime(a, 1))
    except:
        break

# IsPrime(10000000, 2)

a, b = map(int, input().split())

for i in range(a, b+1):
    if str(i) == str(i)[::-1]:
        if not Del[i]:
            print(i)