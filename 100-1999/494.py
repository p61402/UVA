# Run Time: 0.010
def main():
    while True:
        try:
            line = input()
        except EOFError:
            break

        word_count = 0
        previous_one_is_alpha = False
        for word in line:
            if word.isalpha():
                previous_one_is_alpha = True
            else:
                if previous_one_is_alpha:
                    word_count += 1
                previous_one_is_alpha = False

        print(word_count)


if __name__ == '__main__':
    main()
