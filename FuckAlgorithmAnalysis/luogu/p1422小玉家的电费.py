def compute_money(kilowatts):
    if kilowatts <= 150:
        return kilowatts*0.4463
    elif kilowatts > 150 and kilowatts <= 400:
        return 150*0.4463 + (kilowatts-150)*0.4663
    else:
        return compute_money(400) + (kilowatts-400)*0.5663


# kilowatts = map(int, input().split())
kilowatts = int(input())
print(round(compute_money(kilowatts), 1))
