is_prime = [True]*23333
prime_num = []
def IsPrime(num, flag):
    if flag == 0:
        for i in range(2, num):
            if num%i == 0:
                return False
        return True
    elif flag == 1: #埃式筛
        # is_prime = [True]*(num+1)
        is_prime[0] = is_prime[1] = False # 0 and 1 is not prime
        for i in range(2, num+1):
            if is_prime[i]:
                for j in range(i*i, num+1, i):
                    is_prime[j] = False
        return is_prime[num]
    elif flag == 2: #欧拉筛
        # is_prime = [True]*(num+1)
        # prime_num = []
        is_prime[0] = is_prime[1] = False # 0 and 1 is not prime
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
IsPrime(20001, 2)
# print(is_prime[:100])
n = int(input())
# n = 17079

flag = 1
def dfs(n, sln, layer):
    global flag
    if layer == 2:
        if is_prime[n]:
            sln[layer] = n
            flag = 0
            for i in sln:
                print(i, end = " ")
            print()
        # if n == 0:
        #     flag = 0
        #     for i in sln:
        #         print(i, end = " ")
        #     print()
    else:
        for i in range(2, n+1):
            if is_prime[i] and n-i>=0 and flag:
                n -= i
                sln[layer] = i
                dfs(n, sln, layer+1)
                n += i

sln = [0]*3
dfs(n, sln, 0)