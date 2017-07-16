# Run Time: 0.020
def main():
    dictionary = {}
    while True:
        try:
            english_word, foreign_word = input().split()
            dictionary[foreign_word] = english_word
        except ValueError:
            break
    while True:
        try:
            word = input()
            if word in dictionary:
                print(dictionary[word])
            else:
                print("eh")
        except EOFError:
            break


if __name__ == '__main__':
    main()
