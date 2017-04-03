# Run Time: 0.010
def find_natural_q(integer_n):
    q = ""

    if integer_n == 0 or integer_n == 1:
        return integer_n

    for divisor in range(9, 1, -1):
        while True:
            if integer_n % divisor == 0:
                integer_n /= divisor
                q += str(divisor)
                continue
            else:
                break

    if integer_n == 1:
        return sort_str(q)
    else:
        return -1


def sort_str(str_q):
    list_q = list(str_q)
    list_q.sort()
    new_str_q = "".join(list_q)
    return new_str_q


num_of_cases = int(input())
for n in range(num_of_cases):
    N = int(input())
    natural_q = find_natural_q(N)
    print(natural_q)
