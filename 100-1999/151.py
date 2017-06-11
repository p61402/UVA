# Run Time: 0.040
def main():
    while True:
        n = int(input())
        if n == 0:
            break

        for m in range(1, 1000):
            # print("Turn:", m)
            region = [number for number in range(n)]
            pos = 0
            count = 0
            while count != n - 1:
                # print("kill", region[pos])
                region[pos] = -1
                count += 1
                run = 0
                while run != m:
                    pos += 1
                    if pos >= n:
                        pos -= n
                    if region[pos] != -1:
                        run += 1
            # print("rest", region[pos])
            if region[pos] == 12:
                print(m)
                break

if __name__ == '__main__':
    main()
