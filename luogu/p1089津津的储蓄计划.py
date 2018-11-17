budget = []
money_in_hand = 0
money_in_mom = 0
flag = True
for i in range(12):
    money_in_hand += 300
    budget.append(int(input()))
    
    if not flag:
        continue

    money_in_hand -= budget[i]
    if money_in_hand < 0:
        flag = False
        print(-(i+1))
    else:
        money_in_mom += money_in_hand//100*100
        money_in_hand %= 100

if flag:
    print(int(money_in_mom*1.2 + money_in_hand))