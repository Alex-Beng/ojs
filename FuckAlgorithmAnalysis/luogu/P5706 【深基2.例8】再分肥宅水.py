t, n = input().split()
t = float(t)
n = int(n)


cap_n = n*2
cola_ml = t/n

t_n = int(cola_ml*10000)%10

if t_n >= 5:
    cola_ml = (int(cola_ml*1000)+1)*1.0/1000
else:
    cola_ml = (int(cola_ml*1000))*1.0/1000

print(cola_ml)
print(cap_n)
