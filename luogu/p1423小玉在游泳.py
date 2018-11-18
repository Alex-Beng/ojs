from math import *
distance = float(input())
print(int(log(1-0.01*distance)/log(0.98) - 1))