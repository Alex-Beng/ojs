raw_str = input()

treatment_flag = ''

if '.' in raw_str:
    treatment_flag = '.'
elif '/' in raw_str:
    treatment_flag = '/'
elif '%' in raw_str:
    treatment_flag = '%'
else:
    treatment_flag = ''

print(str(int(str(int(raw_str[:raw_str.index(treatment_flag)]))[::-1])) + treatment_flag + str(int(str(int(raw_str[raw_str.index(treatment_flag)+1:]))[::-1])))

# if treatment_flag != '' and treatment_flag != '%':
#     digits = list(raw_str)
#     former = [digits[i] for i in range(len(digits)) if i < digits.index(treatment_flag)]
#     former = list(str(int("".join(former))))

#     latter = [digits[i] for i in range(len(digits)) if i > digits.index(treatment_flag)]
#     latter = list(str(int("".join(latter))))
#     print(str(int("".join(former[::-1]))) + treatment_flag + str(int("".join(latter[::-1]))))
# elif treatment_flag == '':
#     print(raw_str[::-1])
# else:
#     digits = list(raw_str)
#     del digits[-1]
#     print("".join(digits)[::-1]+'%')