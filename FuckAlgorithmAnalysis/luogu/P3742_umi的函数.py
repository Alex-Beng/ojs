if __name__ == "__main__":
    n = int(input())
    x = input()
    z = input()
    ans = ''

    for i in range(len(x)):
        if z[i] > x[i]:
            ans = '-1'
            break
        else:
            ans += min(z[i], x[i])
    print(ans)