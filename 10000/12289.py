# Run Time: 0.030
def main():
    num = int(input())

    for i in range(num):
        word = input()

        if len(word) == 5:
            print(3)
        else:
            if (word[0] == "o" and word[1] == "n") or (word[0] == "o" and word[2] == "e") or (word[1] == "n" and word[2] == "e"):
                print(1)
            else:
                print(2)


if __name__ == "__main__":
    main()
