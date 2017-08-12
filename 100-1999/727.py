def main():
    stack = []
    test_case = int(input())
    input()
    case_count = 0
    output = ""
    while case_count != test_case:
        try:
            char = input()
        except EOFError:
            while len(stack):
                output += stack.pop()
            print(output)
            if case_count != test_case - 1:
                print()
            break

        if len(char) == 0:
            while len(stack):
                output += stack.pop()
            print(output)
            if case_count != test_case - 1:
                print()
            case_count += 1
            stack.clear()
            output = ""
            continue

        if char.isnumeric():
            output += char
        elif char == "(":
            stack.append(char)
        elif char == ")":
            while True:
                c = stack.pop()
                if c != "(":
                    output += c
                else:
                    break
        else:
            while len(stack) and stack[-1] != "(" and (stack[-1] in "*/" or (stack[-1] in "+-" and char in "+-")):
                output += stack.pop()
            stack.append(char)


if __name__ == '__main__':
    main()
