# Run Time: 0.010
def main():
    n = int(input())
    countries = {}
    for i in range(n):
        a = input().split()
        if a[0] not in countries:
            countries[a[0]] = 1
        else:
            countries[a[0]] += 1
    for key, value in sorted(countries.items()):
        print(key, value)


if __name__ == '__main__':
    main()
