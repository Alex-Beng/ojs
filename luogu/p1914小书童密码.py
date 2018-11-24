n = int(input())
raw_password = input()

pw_words = [chr(ord('a')+(ord(i)-ord('a')+n)%26) for i in list(raw_password)]
print("".join(pw_words))