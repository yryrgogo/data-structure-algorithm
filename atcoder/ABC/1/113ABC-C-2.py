N, M = map(int, input().split(' '))

cities = []
for i in range(M):
    p, y = map(int, input().split(' '))
    cities.append([p, y, i])

cities = sorted(cities, key=lambda x: x[1])
cities = sorted(cities, key=lambda x: x[0])

p = cities[0][0]
cnt = 1
for i in range(M):

    if (cities[i][0] == p):
        cities[i].append(str(p).zfill(6) + str(cnt).zfill(6))
        cnt += 1
    else:
        p = cities[i][0]
        cnt = 1
        cities[i].append(str(p).zfill(6) + str(cnt).zfill(6))
        cnt += 1

cities = sorted(cities, key=lambda x: x[2])

for i in range(M):
    print(cities[i][3])
