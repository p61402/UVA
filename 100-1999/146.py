# Run Time: 0.010
def next_permutation(s):
    for i in range(len(s) - 2, -1, -1):
        for j in range(len(s) - 1, i, -1):
            if s[i] < s[j]:
                s[i], s[j] = s[j], s[i]
                return reverse(s, i + 1)


def reverse(s, start):
    reverse_s = s[start:]
    s[start:] = reversed(reverse_s)

    return s


def main():
    while True:
        code = input()
        if code == "#":
            break

        code_list = list(code)

        next_code_list = next_permutation(code_list)

        if next_code_list is None:
            print("No Successor")
        else:
            next_code = "".join(next_code_list)

            print(next_code)


if __name__ == "__main__":
    main()
