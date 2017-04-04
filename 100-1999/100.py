# Run Time: 2.750
def cycle_length(n):
    if n == 1:
        return 1
    elif n & 1 == 1:
        return 1 + cycle_length(3 * n + 1)
    else:
        return 1 + cycle_length(n >> 1)

cache = {}
for i in range(1, 10000):
    cache[i] = cycle_length(i)

while True:
    try:
        i, j = input().split()
    except EOFError:
        break

    i = int(i)
    j = int(j)

    print("{0} {1}".format(i, j), end=" ")

    if i > j:
        i, j = j, i

    max_cycle_length = 0

    for number in range(i, j + 1):
        if number in cache:
            current_cycle_length = cache[number]
        else:
            current_cycle_length = cycle_length(number)
            cache[number] = current_cycle_length

        if current_cycle_length > max_cycle_length:
            max_cycle_length = current_cycle_length

    print(max_cycle_length)
