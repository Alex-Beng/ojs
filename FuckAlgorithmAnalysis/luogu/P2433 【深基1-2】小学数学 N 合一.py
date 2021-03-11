n = int(input())

if n == 1:
    print("I love Luogu!")
elif n == 2:
    print("6 4")
elif n == 3:
    print(14//4)
    print(14//4*4)
    print(14 - 14//4*4)
elif n == 4:
    print("%.3f"%(500.0/3))
elif n == 5:
    print((260+220)//(12+20))
elif n == 6:
    from math import sqrt
    print(sqrt(6*6+9*9))
elif n == 7:
    print(100+10)
    print(100+10-20)
    print(0)
elif n == 8:
    r = 5.0
    pi = 3.141593
    print(2*pi*r)
    print(pi*r*r)
    print(4*pi*r*r*r/3)
elif n == 9:
    def recov(n):
        return (n+1)*2
    left = 1
    for i in range(3):
        left = recov(left)
    print(left)
elif n == 10:
    print(9)
elif n == 11:
    print(100./3)
elif n == 12:
    print(ord('M')-ord('A')+1)
    print(chr(ord('A')+17))
elif n == 13:
    def ball_V(r):
        pi = 3.141593
        return 4.0*pi*r*r*r/3
    from math import pow
    print(int(pow(ball_V(4)+ball_V(10), 1.0/3)))
elif n == 14:
    print(50)