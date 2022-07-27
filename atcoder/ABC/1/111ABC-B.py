N = input()


def main():

    cnt = int(N)
    while True:
        if cnt % 111 == 0:
            print(cnt)
            return
        cnt += 1


main()
