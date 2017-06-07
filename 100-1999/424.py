# Run Time: 0.010
def main():
    num = 0
    while True:
        value = int(input())
        num += value
        if value == 0:
            break
    print(num)


if __name__ == '__main__':
    main()
