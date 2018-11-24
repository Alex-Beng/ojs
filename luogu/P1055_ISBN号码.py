raw_str = input()

letters = list(raw_str)
nums = [int(i) for i in letters if i != '-']

last_digit = nums[-1]
del nums[-1]

t = 1
sum = 0
for i in nums:
    sum += i*t
    t += 1

if sum%11 == last_digit:
    print("Right")
else:
    del letters[-1]
    letters.append(str(sum%11))
    print("".join(letters))
    