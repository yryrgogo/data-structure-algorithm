from collections import defaultdict

n = int(input())
V = list(map(int, input().split()))

odd = defaultdict(int)
even = defaultdict(int)

max_odd = 0
max_even = 0
f_odd = 0
f_even = 0
s_odd = 0
s_even = 0

for i, v in enumerate(V[:-2]):
    i += 1
    if i % 2 == 0:
        even[v] += 1
        if even[v] > max_even:
            max_even = even[v]
            if f_even != 0 and v != f_even:
                s_even = f_even
                f_even = v
            elif f_even == 0:
                f_even = v

    elif i % 2 == 1:
        odd[v] += 1
        if odd[v] > max_odd:
            max_odd = odd[v]
            if f_odd != 0 and v != f_odd:
                s_odd = f_odd
                f_odd = v
            elif f_odd == 0:
                f_odd = v

half = (n - 2) / 2
cnt = 0

if f_odd != f_even:
    c1 = (half - max_odd) + (half - max_even)
    c2 = (half - max_even) + (half - max_odd)
    if c1 > c2:
        cnt = c2
    else:
        cnt = c1
    num1 = f_odd
    num2 = f_even
elif f_odd == f_even:
    c1 = (half - max_odd) + (half - even[s_even])
    c2 = (half - max_even) + (half - odd[s_odd])
    if c1 > c2:
        cnt = c2
        num1 = s_odd
        num2 = f_even
    else:
        cnt = c1
        num1 = f_odd
        num2 = s_even

last_odd = V[-2]
last_even = V[-1]
if last_odd != num1 and last_odd != num2:
    cnt += 1
if last_even != num1 and last_even != num2:
    cnt += 1

# print(f'{last_odd}, {last_even}, {num1}, {num2}')
print(int(cnt))
