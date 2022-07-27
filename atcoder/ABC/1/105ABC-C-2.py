n = int(input())

ans = ''

a = n
while True:
    if abs(a) % 2 == 1:
        a -= 1
        ans = '1' + ans
    else:
        ans = '0' + ans

    if abs(a) == 0:
        break
    a /= -2

print(ans)
